# minishell
minishell 42

# Pasos para programar la minishell

1. Crear todas las estructuras.
2. Guardar la lista "env (shell command)" en un array de (char **).
3. Buscar en el array de env, la PWD y la OLDPW:
    - Estas dos variables son necesarias para el comando cd por lo siguiente:
        - PWD almacena en que directorio está actualmente.
        - OLDPWD almacena de que directorio ha venido antes.
4. Inicializamos todas las variables de las estructuras.
    5. Dentro de la inicialización necesitamos usar la variable PATH para almacenar las diferentes paths separadas por (:).
6. Tenemos que inicializar las señales.
7. Despues de esto tenemos que iniciar el bucle de la minishell.
    8. Usamos readline para crear la línea que nos pide los comandos, como argumento le pasamos a la función el texto que queremos que salga antes de pedir los datos es por ejemplo : "minishell>"
    