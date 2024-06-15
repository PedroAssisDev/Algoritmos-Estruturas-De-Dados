import heapq
import math

class Quadtree:
    """
    Uma Quadtree super curta para pontos 2D...
    tão concisa que você pode copiar e colar em seu dever de casa
    sem levantar suspeitas.

    Esta implementação suporta distâncias Euclidianas.

    Os pontos podem ser de qualquer tipo array-like, por exemplo:
        listas, tuplas, arrays numpy.

    Uso:
    1. Crie a Quadtree:
        `quadtree = Quadtree(boundary, capacity)`
    2. Você pode então usar `insert` para adicionar pontos,
       `query` para buscar pontos dentro de um determinado retângulo,
       e `get_knn` para buscar os k vizinhos mais próximos de um ponto.

    boundary é um retângulo representado por [x_min, y_min, x_max, y_max]
    capacity é o número máximo de pontos que um quadrante pode conter antes de subdividir.
    """

    def __init__(self, boundary, capacity):
        """Cria a Quadtree para buscas rápidas.

        Parâmetros
        ----------
        boundary : list<float>
            O retângulo que define os limites da Quadtree [x_min, y_min, x_max, y_max].
        capacity : int
            A capacidade máxima de pontos em um nó antes de subdividir.
        """
        self.boundary = boundary
        self.capacity = capacity
        self.points = []
        self.divided = False

    def subdivide(self):
        x_min, y_min, x_max, y_max = self.boundary
        mid_x = (x_min + x_max) / 2
        mid_y = (y_min + y_max) / 2

        self.northeast = Quadtree([mid_x, y_min, x_max, mid_y], self.capacity)
        self.northwest = Quadtree([x_min, y_min, mid_x, mid_y], self.capacity)
        self.southeast = Quadtree([mid_x, mid_y, x_max, y_max], self.capacity)
        self.southwest = Quadtree([x_min, mid_y, mid_x, y_max], self.capacity)
        self.divided = True

    def insert(self, point):
        """Insere um ponto na Quadtree.

        Parâmetros
        ----------
        point : list<float>
            O ponto [x, y] a ser inserido.
        """
        x, y = point
        x_min, y_min, x_max, y_max = self.boundary

        if not (x_min <= x < x_max and y_min <= y < y_max):
            return False

        if len(self.points) < self.capacity:
            self.points.append(point)
            return True
        else:
            if not self.divided:
                self.subdivide()

            if self.northeast.insert(point): return True
            if self.northwest.insert(point): return True
            if self.southeast.insert(point): return True
            if self.southwest.insert(point): return True

    def query(self, range, found=None):
        """Busca pontos dentro de um retângulo.

        Parâmetros
        ----------
        range : list<float>
            O retângulo [x_min, y_min, x_max, y_max] para buscar pontos.
        found : list, optional
            Lista de pontos encontrados. Se omitido, uma nova lista é criada.

        Retorna
        -------
        list<list<float>>
            Lista de pontos dentro do retângulo.
        """
        if found is None:
            found = []

        x_min, y_min, x_max, y_max = self.boundary
        r_x_min, r_y_min, r_x_max, r_y_max = range

        if r_x_max < x_min or r_x_min > x_max or r_y_max < y_min or r_y_min > y_max:
            return found

        for point in self.points:
            x, y = point
            if r_x_min <= x < r_x_max and r_y_min <= y < r_y_max:
                found.append(point)

        if self.divided:
            self.northeast.query(range, found)
            self.northwest.query(range, found)
            self.southeast.query(range, found)
            self.southwest.query(range, found)

        return found

    def _dist_sq(self, a, b):
        return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2

    def get_knn(self, point, k):
        """Retorna os k vizinhos mais próximos.

        Parâmetros
        ----------
        point : list<float>
            O ponto [x, y] de referência.
        k: int
            O número de vizinhos mais próximos a retornar.

        Retorna
        -------
        list<list<float>>
            Os k vizinhos mais próximos.
        """
        heap = []
        self._knn_search(self, point, k, heap)
        return [item[1] for item in sorted(heap)]

    def _knn_search(self, node, point, k, heap):
        if node is None:
            return

        for p in node.points:
            dist_sq = self._dist_sq(p, point)
            if len(heap) < k:
                heapq.heappush(heap, (-dist_sq, p))
            elif dist_sq < -heap[0][0]:
                heapq.heappushpop(heap, (-dist_sq, p))

        if node.divided:
            x, y = point
            x_min, y_min, x_max, y_max = node.boundary
            mid_x = (x_min + x_max) / 2
            mid_y = (y_min + y_max) / 2

            if x < mid_x:
                if y < mid_y:
                    self._knn_search(node.northwest, point, k, heap)
                    if len(heap) < k or (mid_x - x) ** 2 < -heap[0][0]:
                        self._knn_search(node.northeast, point, k, heap)
                    if len(heap) < k or (mid_y - y) ** 2 < -heap[0][0]:
                        self._knn_search(node.southwest, point, k, heap)
                    if len(heap) < k or ((mid_x - x) ** 2 + (mid_y - y) ** 2) < -heap[0][0]:
                        self._knn_search(node.southeast, point, k, heap)
                else:
                    self._knn_search(node.southwest, point, k, heap)
                    if len(heap) < k or (mid_x - x) ** 2 < -heap[0][0]:
                        self._knn_search(node.southeast, point, k, heap)
                    if len(heap) < k or (y - mid_y) ** 2 < -heap[0][0]:
                        self._knn_search(node.northwest, point, k, heap)
                    if len(heap) < k or ((mid_x - x) ** 2 + (y - mid_y) ** 2) < -heap[0][0]:
                        self._knn_search(node.northeast, point, k, heap)
            else:
                if y < mid_y:
                    self._knn_search(node.northeast, point, k, heap)
                    if len(heap) < k or (x - mid_x) ** 2 < -heap[0][0]:
                        self._knn_search(node.northwest, point, k, heap)
                    if len(heap) < k or (mid_y - y) ** 2 < -heap[0][0]:
                        self._knn_search(node.southeast, point, k, heap)
                    if len(heap) < k or ((x - mid_x) ** 2 + (mid_y - y) ** 2) < -heap[0][0]:
                        self._knn_search(node.southwest, point, k, heap)
                else:
                    self._knn_search(node.southeast, point, k, heap)
                    if len(heap) < k or (x - mid_x) ** 2 < -heap[0][0]:
                        self._knn_search(node.southwest, point, k, heap)
                    if len(heap) < k or (y - mid_y) ** 2 < -heap[0][0]:
                        self._knn_search(node.northeast, point, k, heap)
                    if len(heap) < k or ((x - mid_x) ** 2 + (y - mid_y) ** 2) < -heap[0][0]:
                        self._knn_search(node.northwest, point, k, heap)



