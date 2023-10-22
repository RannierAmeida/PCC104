
int main() {
    std::queue<int> fila;

    fila.push(10);
    fila.push(20);
    fila.push(30);

    std::cout << "Elemento da frente da fila: " << fila.front() << std::endl;

    fila.pop();
    std::cout << "Elemento da frente após pop: " << fila.front() << std::endl;

    return 0;
}
