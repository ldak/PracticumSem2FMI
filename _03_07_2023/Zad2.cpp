//
// Created by MILEN_PC on 3/15/2023.
//

#include <iostream>
#include <fstream>
#include <cstring>

struct Offer{
    char name[26];
    int teamMembers;
    int paidLeave;
    int pay;

    Offer(){}

    Offer(const char* name, int teamMembers, int payLeave, int pay){
        std::strcpy(this->name, name);
        this->teamMembers = teamMembers;
        this->paidLeave = payLeave;
        this->pay = pay;
    }

    void print() const{
        std::cout << "name: "  << this->name << std::endl;
        std::cout << "team members: " << this->teamMembers << std::endl;
        std::cout << "paid leave: " << this->paidLeave << std::endl;
        std::cout << "pay: " << this->pay << std::endl << std::endl;
    }
};

Offer initOfferFromConsole(){
    char name[26];
    std::cin >> name;
    int team, payLeave, pay;
    std::cin >> team >> payLeave >> pay;

    return {name, team, payLeave, pay};
}

long long fileSize(std::ifstream& ifs){
    if (!ifs.is_open())
        return -1;

    long long current = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    long long size = ifs.tellg();
    ifs.seekg(current, std::ios::beg);

    return size;
}

void loadOffers(char* fileName, int &size, Offer* &offers){
    std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
    int sizeOfTheFile = fileSize(ifs);
    if (sizeOfTheFile > 0){
        size = sizeOfTheFile/sizeof(Offer);

        offers = new Offer[size ];
        ifs.read((char*) offers, sizeOfTheFile);

    }else{
        offers = new Offer[0];
        size = 0;
    }
    ifs.close();
}


void showOffers(Offer* offers, int length){
   for(int i = 0; i < length; i++){
       offers[i].print();
   }
}

void writeOfferToFile(std::ofstream &ofs, const Offer& offer){
    if (!ofs.is_open()){
        return;
    }

    ofs.write((char*)&offer, sizeof(offer));
}

void addOffers(const char* fileName,Offer* &offersList, int& length ){

    std::ofstream ofs(fileName, std::ios::out | std::ios::app | std::ios::binary);

    int size;
    std::cin >> size;
    Offer* offers = new Offer[size];
    for (int i = 0; i < size; ++i) {
        offers[i] = initOfferFromConsole();
        writeOfferToFile(ofs, offers[i]);
    }
    length +=size;
    Offer* temp = new Offer[length];
    for (int i = 0; i < length - size; ++i) {
        temp[i] = offersList[i];
    }
    for(int i = 0; i < size; ++i){
        temp[i + length - size] = offers[i];
    }
    delete[] offersList;
    offersList = temp;
}

void checkForCompany(const Offer * offers, int length) {
    char* firmName;
    std::cin >> firmName;
    for (int i = 0; i < length ; ++i) {
        if (strcmp(offers[i].name, firmName) == 0) {
            std::cout << "exists" << std::endl;
            offers[i].print();
            return;
        }
    }
    std::cout << "does not exists" << std::endl;
}

void filter(Offer* offers, int length) {
    int salary;
    std::cin >> salary;
    for (int i = 0; i < length; ++i) {
        if (offers[i].pay > salary)
            offers[i].print();
    }
}

void programLoop(Offer* &offers, int &length, const char* fileName){
    char a;
    do{
        std::cout << "enter command:";
        std::cin >> a;
        switch(a){
            case 'i': showOffers(offers, length);
                break;
            case 'a':
                addOffers(fileName, offers, length);
                break;
            case 's':
                checkForCompany(offers, length);
                break;
            case 'f':
                filter(offers, length);
            default:
                std::cout << "not a command" << std::endl;

        }
    }while(a != 'q');

}

int main(){

    char fileName[] = "hristo.dat";
    int length;
    Offer* offers;
    loadOffers(fileName, length, offers);

    programLoop(offers, length, fileName);


    return 0;
}
