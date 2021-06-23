#include<iostream>
using namespace std;
class flight;
void registeration()
{
    flight new;
    cout<<"--------FLIGHT REGISTERATION---------\n";
    cout<<"type of flight";
    cin>>new.type;

}
class flight{
private:
    string time;
    string model;
    string type;
    int passengers;
    int runway;
    int flight_number;
    int id;
    flight* nextFlight;
public:
    flight(){

    }
    flight(){

    }
    void set_time(string time)
    {
       this->time = time;
    }
    void set_model(string model)
    {
        this->model = model;
    }
    void set_type(string type)
    {
        this->type = type;
    }
    void set_passengers(int passengers)
    {
        this->passengers = passengers;
    }
    void set_runway(int runway)
    {
        this->runway = runway;
    }
    void set_flight_number(int flight_number)
    {
        this->flight_number = flight_number;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void setNextflight(flight *nextFlight)
    {
        this->nextFlight = nextFlight;
    }
    string get_time()
    {
        return time;
    }
    string get_model()
    {
        return model;
    }
    string get_type()
    {
        return type;
    }
    int get_passengers()
    {
        return passengers;
    }
    int get_runway()
    {
        return runway;
    }
    int get_flight_number()
    {
        return flight_number;
    }
    int get_id()
    {
        return id;
    }
    flight * getNextflight()
    {
        return nextFlight;
    }
};
class Airport{
private:
    flight * first=nullptr;
    int number_of_flights;
public:
    map <string, int> airplane_size;
    int runways[5][48];
    Airport () {

    }
    void insert() {

    }
    void sort() {

    }
    void print() {

    }
    void Delete() {

    }
    flight * searchById() {

    }
    flight * searchByFlightNumber() {

    }
};

int main()
{
    cout<<"**   **  **** **    **    **  ****   **      ***   *****    **     **  **** \n";
    cout<<"**   **   **   **   **   **   **     **    **     *     *   ** * * **  **\n";
    cout<<"*******   **    **  **  **    ***    **    **     *     *   **  *  **  ***\n";
    cout<<"**   **   **     ** ** **     **     **    **     *     *   **     **  **\n";
    cout<<"**   **  ****     **  **      ****   *****   ***   *****    **     **  ****\n";
    int num;
    do{
    cout<<"\n\n( 1 ) Flight profile registration\n";
    cout<<"( 2 ) Add flight flight list\n";
    cout<<"( 3 ) Cancel flight from flight list\n";
    cout<<"( 4 ) Sort flights by departure time\n";
    cout<<"( 5 ) Show flights\n";
    cout<<"( 0 ) Exit\n";
    cout<<"choose one : ";
    cin>>num;
      switch(num){
      case 1:
        Airport::insert();
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      }
    }while(num!=0);

}
