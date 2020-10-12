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

// Nodo de una lista doblemente ligada (LDL)
struct Node { 
    std::string data; 
    struct Node* prev, *next; 
}; 

// Inserta un nuevo nodo al principio de la lista dada una referencia (pointer a pointer) del head y un int
void push(Node** head_ref, std::string new_data)  {  
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

// Crea y devuelve nuevo nodo de LDL 
struct Node* getNode(std::string data) { 
    // Ubica Nodo
    struct Node* newNode =  
        (struct Node*)malloc(sizeof(struct Node)); 
    // Inserta dato
    newNode->data = data; 
    newNode->prev = newNode->next = NULL; 
    return newNode; 
} 
  
// Inserta nuevo nodo de forma ordenada en LDL
void insercionOrdenada(struct Node** head_ref, struct Node* newNode) { 
    struct Node* current; 
    // Si LDL esta vacía
    if (*head_ref == NULL) 
        *head_ref = newNode; 
    // Agregar al principio de la lista
    else if ((*head_ref)->data >= newNode->data) { 
        newNode->next = *head_ref; 
        newNode->next->prev = newNode; 
        *head_ref = newNode; 
    } else { 
        current = *head_ref; 
        // Ubicar nodo previo al nodo que debe ser insertado
        while (current->next != NULL &&  
               current->next->data < newNode->data) 
            current = current->next; 
        // Crear vínculo
        newNode->next = current->next; 
        // Si nodo no es insertado el final
        if (current->next != NULL) 
            newNode->next->prev = newNode; 
        current->next = newNode; 
        newNode->prev = current; 
    } 
} 

// Function to insetail new node  
void nodeInsetail(Node **head, Node **tail, std::string key)  
{  
  
    Node *p = new Node();  
    p->data = key;  
    p->next = NULL;  
  
    // If first node to be insetailed in doubly  
    // linked list  
    if ((*head) == NULL)  
    {  
        (*head) = p;  
        (*tail) = p;  
        (*head)->prev = NULL;  
        return;  
    }  
  
    // If node to be insetailed has value less  
    // than first node  
    if ((p->data) < ((*head)->data))  
    {  
        p->prev = NULL;  
        (*head)->prev = p;  
        p->next = (*head);  
        (*head) = p;  
        return;  
    }  
  
    // If node to be insetailed has value more  
    // than last node  
    if ((p->data) > ((*tail)->data))  
    {  
        p->prev = (*tail);  
        (*tail)->next = p;  
        (*tail) = p;  
        return;  
    }  
  
    // Find the node before which we need to  
    // insert p.  
    Node *temp = (*head)->next;  
    while ((temp->data) < (p->data))  
        temp = temp->next;  
  
    // Insert new node before temp  
    (temp->prev)->next = p;  
    p->prev = temp->prev;  
    temp->prev = p;  
    p->next = temp;  
}  
  
// Función para imprimir la LDL
void printList(Node *temp)  
{  
    while (temp != NULL)  
    {  
        std::cout << temp->data << " ";  
        temp = temp->next;  
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

// Solicitud a usuario de rango de IPs para realizar la búsqueda
void ipsFiltro(struct Node* head){
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
    resultadosBusqueda << "ipAddress,dateTime,errorMessage\n";
    while (head != NULL) { 
        resultadosBusqueda << head->data << "\n";
        std::cout << head->data << "\n";
        head = head->next; 
    } 
    // Mensaje de Confirmación
    std::cout << "\nLos resultados de su búsqueda han sido almacenados en la carpeta output (formato CSV). \n";
}

int main() {
    Node *head = NULL, *right = NULL;
    std::string line;
    std::ofstream bitacoraOrdenada;
    // Archivo a grabar con datos ordenados
    bitacoraOrdenada.open ("output/bitacora_AZ.csv");
    // Vector de Strings para almacenar lectura de archivo

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
        cleanedLine.append(ip).append(",").append(datetime).append(",").append(message);

        // struct Node* new_node = getNode(cleanedLine);
        nodeInsetail(&head, &right, cleanedLine);
    };

    printList(head);

    bitacoraOrdenada << "ipAddress,dateTime,errorMessage\n";
    while (head != NULL) { 
        bitacoraOrdenada << head->data << "\n"; 
        head = head->next; 
    } 
    bitacoraOrdenada.close();

    // Variables y función para búsqueda
    ipsFiltro(head);

    return 0;
}