/*
Programa para analizar logs de intentos fallidos de ingreso (bitacora.txt).
    
    Matías Kochlowski – a01625364
    Esteban Sánchez - a01251440
    Michelle Arceo - a01625268

Creación: Sábado, 10 de Octubre
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>

// Nodo de una lista doblemente ligada
struct Node { 
    int data; 
    struct Node* prev, *next; 
}; 

// Inserta un nuevo nodo al principio de la lista dada una referencia (pointer a pointer) del head y un int
void push(Node** head_ref, int new_data)  {  
    // Ubica nodo
    Node* new_node = new Node();  
    // Ingresa la data
    new_node->data = new_data;  
    // Convierte el next de nuevo nodo a head y previo a null
    new_node->next = (*head_ref);  
    new_node->prev = NULL;  
    // Convierte previo de nodo head a nuevo nodo
    if ((*head_ref) != NULL)  
        (*head_ref)->prev = new_node;  
    // Apunta head a nuevo nodo
    (*head_ref) = new_node;  
}  

// Inserta nuevo nodo después de nodo dado como prev_node
void insertAfter(Node* prev_node, int new_data)  {  
    // Verifica si prev_node es null
    if (prev_node == NULL)  {  
        cout<<"Nodo previo no puede ser null.";  
        return;  
    }  
    // Ubica nuevo nodo
    Node* new_node = new Node(); 
    // Insertar data
    new_node->data = new_data;  
    // Hacer next de nuevo nodo el next de prev_node
    new_node->next = prev_node->next;   
    // Hacer nuevo nodo el next de prev_node
    prev_node->next = new_node;
    // Hacer previous el prev_node de new_node
    new_node->prev = prev_node;  
    // Cambiar el prev del nodo después del new_node
    if (new_node->next != NULL)  
        new_node->next->prev = new_node;  
}  

// Agrega nuevo nodo al final dado referencia de head y un int
void append(Node** head_ref, int new_data)  {
    // Ubicar Nodo
    Node* new_node = new Node();  
    Node* last = *head_ref; /* used in step 5*/
    // Insertar Data
    new_node->data = new_data;  
    // Nuevo nodo va a ser el último
    new_node->next = NULL;  
    // Si la lista esta vacía, el nuevo nodo debe se el head
    if (*head_ref == NULL) {  
        new_node->prev = NULL;  
        *head_ref = new_node;  
        return;  
    }  
    // Iterar hasta llegar al último nodo
    while (last->next != NULL)  
        last = last->next;  
    // Cambiar el next del último nodo
    last->next = new_node;  
    // Último nodo previous del nuevo nodo
    new_node->prev = last;  
    return;  
}  

// Impresión de contenidos de lista doblemente ligada
void printList(Node* node) {  
    Node* last;  
    cout<<"\nTraversal in forward direction \n";  
    while (node != NULL) {  
        cout<<" "<<node->data<<" ";  
        last = node;  
        node = node->next;  
    }
    cout<<"\nTraversal in reverse direction \n";  
    while (last != NULL) {  
        cout<<" "<<last->data<<" ";  
        last = last->prev;  
    }
}

// Archivo de ingreso raw - mismo archivo que Act. 1.3 - @TODO: ver de usar mismo orígen
std::ifstream bitacora("input/bitacora.txt");

// Reemplazar valores de meses textuales por numericos
std::string mesTextoANro(const std::string& mes) {
    if (mes == "Jun ") return "06-";
    if (mes == "Jul ") return "07-";
    if (mes == "Aug ") return "08-";
    if (mes == "Sep ") return "09-";
    if (mes == "Oct ") return "10-";
    return "";
}

// Quicksort recursivo
void quickSort(std::vector<std::string> &str, int inicio, int fin) {
    int i = inicio, j = fin;
    // Variable para asistir en cambio de valores - SWAP
    std::string buffer;
    // Valor medio en lista
    std::string mid = str[(inicio + fin) / 2];
    while (i <= j) {
        // Contador desde inicio hacia el centro
        while (str[i] < mid)
            i++;
        // Contador desde el final hacia el centro
        while (str[j] > mid)
            j--;
        // Comparador y cambiador de valores - SWAP
        if (i <= j) {
                buffer = str[i];
                str[i] = str[j];
                str[j] = buffer;
                i++; j--;
        }
    };
    // Recursión - función se llama a si misma
    if (inicio < j) quickSort(str, inicio, j);
    if (i < fin) quickSort(str, i, fin);
}

// Solicitud a usuario de rango de fechas para realizar la búsqueda
void fechasFiltro(std::vector<std::string> listaVector){
    std::string ip1, ip2;
    std::cout << "\nEsta base contiene 16,806 registros de intentos fallidos de ingreso al sistema desde 01-Jun hasta 30-Oct y que detalla IPs y puertos origen de requests.\n";
    std::cout << "\nPara realizar una búsqueda, por favor ingrese el rango de IPs deseado en formato 0.0.0.0:0000\n";
    std::cout << "Ingrese IP y Puerto (0.0.0.0:0000). Desde: ";
    std::cin >> ip1;
    std::cout << "Ingrese IP y Puerto (999.999.999.999:9999). Hasta: ";
    std::cin >> ip2;
    std::cout << "Buscando resultados entre " << ip1 << " y " << ip2 << ".\n\n";
    // Creación de archivo y grabado de resultados en carpeta output
    std::ofstream resultadosBusqueda;
    resultadosBusqueda.open ("output/resultados" + ip1 + "a" + ip2 + ".csv");
    resultadosBusqueda << "dateTime,ipAddress,errorMessage\n";
    for(int a = 0; a < listaVector.size(); a++){
        if (listaVector[a] > ip1 && listaVector[a] < ip2 + "z") {
            resultadosBusqueda << listaVector[a] << "\n"; // Graba en archivo CSV
            std::cout << listaVector[a] << "\n"; // Imprime en la consola
        }
    };
    // Mensaje de Confirmación
    std::cout << "\nLos resultados de su búsqueda han sido almacenados en la carpeta output (formato CSV). \n";
}

int main() {
    std::string line;
    std::ofstream bitacoraOrdenada;
    // Archivo a grabar con datos ordenados
    bitacoraOrdenada.open ("output/bitacora_AZ.csv");
    // Vector de Strings para almacenar lectura de archivo
    std::vector<std::string> bitacoraVector;
    // Ciclo while que lee línea por línea hasta llegar al final
    while (std::getline(bitacora, line)){
        std::istringstream iss(line);
        std::string s = line;
        s = s.replace(0,4,mesTextoANro(line.substr (0,4))).replace(5,1,"T");
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);
        std::string datetime = vstrings[0];
        std::string ip = vstrings[1];
        std::string message;
        for(int i = 2; i < vstrings.size(); i++){
            message.append(vstrings[i]).append(" ");
        }
        std::string cleanedLine;
        cleanedLine.append(datetime).append(",").append(ip).append(",").append(message);
        bitacoraVector.push_back(cleanedLine);
    };
    // Llamado función recursiva de ordenamiento
    quickSort(bitacoraVector, 0, bitacoraVector.size()-1);
    // Grabado de bitacora ordenada por fecha y hora a archivo CSV
    bitacoraOrdenada << "dateTime,ipAddress,errorMessage\n";
    for(int b = 0; b < bitacoraVector.size(); b++){
        bitacoraOrdenada << bitacoraVector[b] << "\n";
    };
    bitacoraOrdenada.close();

    // Variables y función para búsqueda
    fechasFiltro(bitacoraVector);

    return 0;
}