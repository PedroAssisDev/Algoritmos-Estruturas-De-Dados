from kd_tree import KDTree
from quad_tree import Quadtree

# Lista de pontos a serem inseridos na QuadTree
points = [
    (-20.7555556, -42.8744444),
    (-21.7641667, -43.3502778),
    (-21.3894444, -42.6894444),
    (-21.5297222, -42.6422222),
    (-21.1302778, -42.3694444),
    (-21.1200000, -42.9355556),
    (-21.2211111, -43.7702778),
    (-21.1355556, -44.2525000),
    (-21.8794444, -42.7175000),
    (-21.4111111, -43.3977778)
]

# Definindo a boundary inicial da QuadTree

# Ponto para encontrar vizinhos
query_point = [-21.5, -43.2]

# Criar uma instância de KDTree
kdtree = KDTree(points, dim=2)

# Encontrar o vizinho mais próximo
nearest_neighbor = kdtree.get_nearest(query_point)
print("Nearest neighbor:", nearest_neighbor)

# Encontrar os 3 vizinhos mais próximos
k = 3
knn = kdtree.get_knn(query_point, k)
print(f"{k} nearest neighbors:", knn)

# Definindo a boundary inicial da QuadTree
boundary = [-22.0, -45.0, -20.0, -42.0]  # [x_min, y_min, x_max, y_max]
capacity = 1

# Criando a Quadtree e inserindo pontos
quadtree = Quadtree(boundary, capacity)
for point in points:
    quadtree.insert(point)

# Ponto para encontrar vizinhos
query_point = [-21.5, -43.2]

# Buscando os 3 vizinhos mais próximos
knn_points = quadtree.get_knn(query_point, 3)
print(knn_points)