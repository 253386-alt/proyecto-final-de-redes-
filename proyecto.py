import streamlit as st
import pandas as pd
import plotly.express as px
from scipy import stats
import google.generativeai as genai
import numpy as np

# --- CONFIGURACIÓN DE PÁGINA ---
st.set_page_config(page_title="IA Estadístico", layout="wide")

# --- BARRA LATERAL (Configuración y API) ---
with st.sidebar:
    st.title("⚙️ Configuración")
    api_key = st.text_input("Introduce tu Gemini API Key", type="password")
    st.info("Obtén tu llave en: https://aistudio.google.com/")
    
    if api_key:
        genai.configure(api_key=api_key)
        model = genai.GenerativeModel('gemini-1.5-flash')

# --- CUERPO PRINCIPAL ---
st.title("📊 Asistente Estadístico Interactivo")

uploaded_file = st.file_uploader("Sube tu archivo CSV para analizar", type=["csv"])

if uploaded_file:
    # Carga de datos
    df = pd.read_csv(uploaded_file)
    
    # Tabs para organizar la interfaz
    tab1, tab2, tab3 = st.tabs(["📈 Distribución", "🧪 Hipótesis", "🤖 Asistente IA"])

    with tab1:
        st.subheader("Visualización de Distribuciones")
        col_num = st.selectbox("Selecciona una columna numérica", df.select_dtypes(include=[np.number]).columns)
        
        fig = px.histogram(df, x=col_num, marginal="box", 
                           title=f"Histograma y Boxplot de {col_num}",
                           color_discrete_sequence=['#00CC96'])
        st.plotly_chart(fig, use_container_width=True)

    with tab2:
        st.subheader("Prueba de Hipótesis (Normalidad)")
        st.write(f"Analizando la columna: **{col_num}**")
        
        # Ejecutar Shapiro-Wilk
        stat, p_value = stats.shapiro(df[col_num].dropna())
        
        col_metric1, col_metric2 = st.columns(2)
        col_metric1.metric("Estadístico W", f"{stat:.4f}")
        col_metric2.metric("P-Value", f"{p_value:.4f}")
        
        if p_value > 0.05:
            st.success("Interpretación: Los datos parecen seguir una distribución normal (No se rechaza H0).")
        else:
            st.warning("Interpretación: Los datos NO siguen una distribución normal (Se rechaza H0).")

    with tab3:
        st.subheader("Pregunta al experto (IA)")
        if not api_key:
            st.error("⚠️ Por favor, ingresa tu API Key en la barra lateral.")
        else:
            pregunta = st.text_input("Ejemplo: ¿Por qué es importante que mis datos sean normales para una prueba T?")
            
            if st.button("Consultar a Gemini"):
                contexto = f"""
                Actúa como un científico de datos senior. 
                El usuario cargó un dataset con las siguientes columnas: {list(df.columns)}.
                En la columna '{col_num}', el test de Shapiro-Wilk dió un p-value de {p_value:.4f}.
                Responde de forma concisa y profesional a la siguiente duda:
                """
                with st.spinner("La IA está analizando..."):
                    try:
                        response = model.generate_content(contexto + pregunta)
                        st.markdown("### Respuesta de la IA:")
                        st.write(response.text)
                    except Exception as e:
                        st.error(f"Hubo un error con la API: {e}")

else:
    st.markdown("""
    ### 🚀 ¡Bienvenido! 
    Para comenzar:
    1. Sube un archivo **CSV**.
    2. Ingresa tu **API Key** de Google en el menú de la izquierda.
    3. Explora las pestañas de visualización y estadística.
    """)