#include <iostream>
#include <cmath>
#include "include/rectangular.hpp"
using namespace std;

void rectangular::output(){
    float length = this->x_maks - this->x_min; length = abs(length);
    float width   = this->y_maks - this->y_min; width   = abs (width);
     cout << "Titik tengah x   : " << (this->x_maks - this->x_min)/2 + this->x_min;  cout <<  endl;
     cout << "Titik tengah y   : " << (this->y_maks - this->y_min)/2 + this->y_min;  cout <<  endl;
     cout << "Panjang          : " << length;  cout <<  endl;
     cout << "Lebar            : " << width;  cout <<  endl;
     cout << "Nilai x_min      : " << this->x_min;  cout <<  endl;
     cout << "Nilai x_max      : " << this->x_maks;  cout <<  endl;
     cout << "Nilai y_min      : " << this->y_min;  cout <<  endl;
     cout << "Nilai y_maks     : " << this->y_maks;  cout <<  endl;
}


rectangular::rectangular(float midpoint_x, float midpoint_y, float length, float width){
    this->x_min = midpoint_x - (length/2);
    this->y_min = midpoint_y - (width/2);
    this->x_maks = midpoint_x + (length/2);
    this->y_maks = midpoint_y + (width/2);
}

bool rectangular::operator==(rectangular const &new_var)const{
    if (this->x_maks > new_var.x_min && this->x_min < new_var.x_maks && this->y_maks > new_var.y_min && this->y_min < new_var.y_maks){
        return true;
    }else{
        return false;
    }
}


rectangular rectangular::operator+(rectangular const &new_var){
    rectangular temp(0,0,0,0);
    if (*this == new_var){
        temp.x_min =  min(this-> x_min,new_var.x_min);
        temp.y_min =  min(this-> y_min,new_var.y_min);
        temp.x_maks =  max(this-> x_maks,new_var.x_maks);
        temp.y_maks =  max(this-> y_maks,new_var.y_maks);
    }else{
         cout << "Objek tidak beririsan" <<  endl;
    }
    return temp;
}


rectangular rectangular::operator-(rectangular const &new_var){
    rectangular temp(0,0,0,0);
    if (*this == new_var){
        temp.x_min =  max(this-> x_min,new_var.x_min);
        temp.y_min =  max(this-> y_min,new_var.y_min);
        temp.x_maks =  min(this-> x_maks,new_var.x_maks);
        temp.y_maks =  min(this-> y_maks,new_var.y_maks);
    }else{
         cout << "Kedua bangun tidak beririsan" <<  endl;
    }
    return temp;
}

void rectangular::operator++(){
    float length = 0, width = 0, midpoint_x = 0, midpoint_y = 0;
    length = this->x_maks - this->x_min; length = abs(length);
    width = this->y_maks - this->y_min; width = abs(width);
    midpoint_x = this->x_min + length/2;
    midpoint_y = this->y_min + width/2;

    length = length * 2;
    width = width * 2;

    this->x_min = midpoint_x - length/2;
    this->y_min = midpoint_y - width/2;
    this->x_maks = midpoint_x + length/2;
    this->y_maks = midpoint_y + width/2;
}

void rectangular::operator--(){
    float length = 0, width = 0, midpoint_x = 0, midpoint_y = 0;
    length = this->x_maks - this->x_min; length = abs(length);
    width = this->y_maks - this->y_min; width = abs(width);
    midpoint_x = this->x_min + length/2;
    midpoint_y = this->y_min + width/2;

    length = length / 2;
    width = width / 2;

    this->x_min = midpoint_x - length/2;
    this->y_min = midpoint_y - width/2;
    this->x_maks = midpoint_x + length/2;
    this->y_maks = midpoint_y + width/2;
}

float rectangular::operator[](int pilihan){
    switch (pilihan){
    case 1:
        return this->x_min;
        break;
    case 2:
        return this->x_maks;
        break;
    case 3:
        return this->y_min;
        break;
    case 4:
        return this->y_maks;
        break;
    }
    return 0;
}