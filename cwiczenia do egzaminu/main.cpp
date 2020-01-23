//
//  main.cpp
//  cwiczenia do egzaminu
//
//  Created by Daniel on 23/01/2020.
//  Copyright © 2020 Daniel Rumin. All rights reserved.
//
//Lista dwukierunkowa
//Wpisywanie na początek
//Wpisywanie na koniec
//Wyświetlanie od tyłu
//Wyświetlanie od początku

#include <iostream>

struct Data {
    int dzien;
    int miesiac;
    int rok;
};

struct Osoba {
    Data data;
    int id;         //Dla wygody wpisujemy tu tylko "ID" zamiast np. Imienia
};

struct Node {
    Osoba osoba; //odwołanie do struktury osoba
    Node * next; //wskazanie na następny element listy
    Node * prev; //wskazanie na poprzedzający element listy
};

struct List {       //Struktura, która zawiera początek i koniec listy
    Node * head;    //będzie ona przekazywana w funkcjach
    Node * tail;    //za pomocą &lista
};                  //(zmienna List * lista)

void ListInnit (List * lista){  //Funkcja, która inicjalizuje listę poprzez przekazanie jej adresu struktury
    lista->head = NULL;
    lista->tail = NULL;
}

void PushFront (List * lista, Osoba * osoba){   //Funkcja wstawiająca komórkę do listy z przodu.
    Node * NewNode;                             //Tymczasowy wskaźnik do przechowywania adresu nowo zallokowanej komórki listy
    NewNode = (Node *)malloc(sizeof(Node));     //Można użyć też NewNode = new Node;
    NewNode->osoba = *osoba;                    //Przypisujemy do nowej komórki adres stworzonej wcześniej struktury z danymi
    NewNode->prev = NULL;                       //Pierwszy element, więc przed nim nie ma nic
    NewNode->next = lista->head;                //Do wskaźnika next z nowej komórki przekazujemy adres 1 komórki listy
    if (lista->head != NULL)
        lista->head->prev = NewNode;            //Wskazanie sprawia, że aktualny head wskazując na poprzedzającą komórkę
    else                                        //bierze adres nowo stworzonej
        lista->tail = NewNode;                  //Jeśli jest to pierwsze wstawienie, to pierwsza komórka jest jednocześnie last
    lista->head = NewNode;                      //Nowej komórce przypisujemy, że jest 1 elementem listy
}

void PushBack (List * lista, Osoba * osoba){    //Funkcja wstawiająca komórkę do listy z tyłu
    Node * NewNode;
    NewNode = (Node *)malloc(sizeof(Node));
    NewNode->osoba = *osoba;
    lista->tail = NewNode;
    NewNode->prev = lista->tail;
    lista->tail = NewNode;
    lista->tail->next = NULL;
}

void ExampleFill_Front (List * lista){
    int OsobyDoZapelnienia = 0;
    std::cout << "Ile osob dodac?: ";
    std::cin >> OsobyDoZapelnienia;
    Osoba persona;
    
    for (int i = 0; i < OsobyDoZapelnienia; ++i) {
        for (int j = 0; j < 4; ++j) {
            
            if (j == 0) {
                persona.data.dzien = i+1;
            } else if (j == 1){
                persona.data.miesiac = i+2;
            } else if (j == 2){
                persona.data.rok = (i+1)*100;
            } else if (j == 3){
                persona.id = i;
            }
        }
        
        PushFront(lista, &persona);
    }
    
}

void ExampleFill_Back (List * lista){
    int OsobyDoZapelnienia = 0;
    std::cout << "Ile osob dodac?: ";
    std::cin >> OsobyDoZapelnienia;
    Osoba persona;
    
    for (int i = 0; i < OsobyDoZapelnienia; ++i) {
        for (int j = 0; j < 4; ++j) {
            
            if (j == 0) {
                persona.data.dzien = i+1;
            } else if (j == 1){
                persona.data.miesiac = i+2;
            } else if (j == 2){
                persona.data.rok = (i+1)*100;
            } else if (j == 3){
                persona.id = i;
            }
            
        }
        PushBack(lista, &persona);
    }
    
}

void DisplayFront (List * lista){
    Node * temp;        //Tymczasowy wskaźnik, który wędruje po liście
    temp = lista->head; //Tymczasowy wskaźnik dostaje 1 komórkę listy
    while (temp != NULL) {
        std::cout << temp->osoba.data.dzien << "/" << temp->osoba.data.miesiac << "/" << temp->osoba.data.rok << "\n";
        std::cout << "Id: " << temp->osoba.id << "\n";
        temp = temp->next; //Tymczasowy wskaźnik przechodzi w następny element listy
    }
}

void DisplayBack (List * lista){
    Node * temp;        //Tymczasowy wskaźnik, który wędruje po liście
    temp = lista->tail; //Tymczasowy wskaźnik dostaje ostatnią komórkę listy
    while (temp != NULL) {
        std::cout << temp->osoba.data.dzien << "/" << temp->osoba.data.miesiac << "/" << temp->osoba.data.rok << "\n";
        std::cout << "Id: " << temp->osoba.id << "\n";
        temp = temp->prev; //Tymczasowy wskaźnik przechodzi do poprzedniego elementu
    }
}

int main() {
    List lista;
    ListInnit(&lista);
    ExampleFill_Front(&lista);
    DisplayFront(&lista);
    std::cout << std::endl;
    DisplayBack(&lista);
    
    
}
