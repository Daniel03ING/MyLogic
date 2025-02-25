
"""/*
  EJERCICIO:
  Utilizando un mecanismo de peticiones HTTP de tu lenguaje, realiza
  una petición a la web que tú quieras, verifica que dicha petición
  fue exitosa y muestra por consola el contenido de la web.
 
  DIFICULTAD EXTRA (opcional):
  Utilizando la PokéAPI (https://pokeapi.co), crea un programa por
  terminal al que le puedas solicitar información de un Pokémon concreto
  utilizando su nombre o número.
  - Muestra el nombre, id, peso, altura y tipo(s) del Pokémon
  - Controla posibles errores
"""
import requests

print("Welcome to the index where you can see your favorite Pokémon!")
print("Please introduce your Pokémon:")

pokemon = input().lower()  # Convert to lowercase to handle case sensitivity
response = requests.get('https://pokeapi.co/api/v2/pokemon/' + pokemon)

if response.status_code == 200:
    data = response.json()
    id = int(data['id'])   
    print(f"ID: {data['id']}")
    print(f"Name: {data['name']}")
    print(f"Height: {data['height']}")
    print(f"Weight: {data['weight']}")
    
    # Extract and print the types
    types = [type_info['type']['name'] for type_info in data['types']]
    print(f"Type: {', '.join(types)}")
else:
    print("The Pokémon you searched for is not available in our database.")



