// 1. Seleccionamos TODOS los elementos que necesitamos
const boton = document.getElementById('botonMagico');
const mensaje = document.getElementById('mensaje');
const titulo = document.getElementById('titulo');
const botonModo = document.getElementById('botonModo');
const inputNombre = document.getElementById('inputNombre'); // ¡Asegúrate de que esta línea esté!

// 2. Lógica del Botón Mágico (El de saludar)
boton.addEventListener('click', () => {
    const nombre = inputNombre.value; // Leemos lo que escribiste en la cajita
    
    if (nombre === "") {
        titulo.textContent = "¡Escribe tu nombre! ✍️";
        titulo.style.color = "red";
    } else {
        titulo.textContent = "¡Hola, " + nombre + "! ✨";
        titulo.style.color = "#0984e3";
        mensaje.style.display = 'block';
        boton.innerText = "¡Hecho!";
    }
});

// 3. Lógica del Modo Oscuro
botonModo.addEventListener('click', () => {
    document.body.classList.toggle('dark-mode');
});