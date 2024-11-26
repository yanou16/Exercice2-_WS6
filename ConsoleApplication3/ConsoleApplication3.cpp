#include <iostream>
#include <stack>
#include <vector>

class SortedList {
private:
    std::stack<int> sortedStack;  // Pile pour stocker la liste triée

public:
    // Constructeur qui prend un vecteur non trié
    SortedList(const std::vector<int>& unsortedList) {
        for (int num : unsortedList) {
            sortedStack.push(num);  // Remplir la pile avec les éléments non triés
        }
    }

    // Méthode pour trier les éléments
    void sort() {
        std::stack<int> tempStack;  // Pile temporaire pour trier les éléments
        while (!sortedStack.empty()) {
            int current = sortedStack.top();  // Prendre le sommet de la pile
            sortedStack.pop();

            // Déplacer les éléments de tempStack qui sont plus grands que l'élément courant
            while (!tempStack.empty() && tempStack.top() > current) {
                sortedStack.push(tempStack.top());
                tempStack.pop();
            }

            // Insérer l'élément dans la pile temporaire
            tempStack.push(current);
        }

        // Copier les éléments triés de tempStack vers sortedStack
        sortedStack = tempStack;
    }

    // Méthode pour afficher les éléments triés
    void print() const {
        std::stack<int> tempStack = sortedStack;  // Copier la pile triée
        while (!tempStack.empty()) {
            std::cout << tempStack.top() << " ";
            tempStack.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> unsortedList = { 1, 11, 3, 7, 5 };
    SortedList sortedList(unsortedList);

    std::cout << "Liste avant tri: ";
    sortedList.print();

    sortedList.sort();

    std::cout << "Liste après tri: ";
    sortedList.print();

    return 0;
}
