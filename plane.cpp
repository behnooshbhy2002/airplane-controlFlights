#include<iostream>
#include<stdio.h>
#include<map>
#include<cstdlib>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
int convert_to_int(string time)
{
        char *c , *str1 , *str2 ;
        int t , hour , minute , t1;

        c = const_cast<char*>(time.c_str());
        str1=strtok( c , ":");
        str2=strtok(NULL , "");
        strcat(str1,str2);
        t = atoi(str1);

        hour= t/100;
        minute= t%100;

        t1 = hour*2 + ( minute >= 30 ? 1 : 0 );
        return t1;
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
    flight(string ti , string mo , string ty , int pass , int run , int fl_nu , int id){
        set_time(ti);
        set_model(mo);
        set_type(ty);
        set_passengers(pass);
        set_runway(run);
        set_flight_number(fl_nu);
        set_id(id);

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
    flight * first;
    int number_of_flights;

public:
    map <string, int> airplane_size;
    int runways[6][49]={0};

    Airport (flight *f=nullptr , int num=0 ) {
         first=f;
         number_of_flights=num;
    }
    void insert(string order)
    {

        string time , model , type;
        int passengers , runway , flight_number , id;

        if(order=="register")
        cout<<"--------FLIGHT REGISTERATION---------\n";

        if(order=="add")
        cout<<"--------FLIGHT ADDITION---------\n";

        cout<<"Plane departure time : ";
        cin>>time;

        cout<<"plane model : ";
        cin>>model;

        cout<<"type of flight (incoming or outgoing): ";
        cin>>type;

        cout<<"Number of flight passengers : ";
        cin>>passengers;

        cout<<"flight number : ";
        cin>>flight_number;

        cout<<"flight id : ";
        cin>>id;

          if(order=="register")
           {
            cout<<"Band number : ";
            cin>>runway;

            int t1=convert_to_int(time);
            runways[runway][t1]=id;
           }

          else if( (type=="outgoing" && searchById(id)) || type=="incoming" )
           {

            cout<<"Band number is ";
            Band(model , time , id);

            map<string, int>::iterator itr;
            itr =  airplane_size.end();
            --itr;
            time=itr->first;
            runway=itr->second;
            cout<<runway;

           }

           if((type=="outgoing" && searchById(id)) || type=="incoming" || order=="register")
           {
            flight *newflight =new flight(time , model , type , passengers , runway , flight_number , id );
            newflight->setNextflight(first);
            first=newflight;
            number_of_flights++;
           }

           else
           {
            flight* current = first;

             while (current != NULL)
             {
                   if (current->get_id() ==id)
                   {
                      current->set_time(time);
                      current->set_model(model);
                      current->set_type(type);
                      current->set_passengers(passengers);
                      current->set_flight_number(flight_number);
                   }

                 current = current->getNextflight();

              }

           }

    }
    void sort()
    {
        flight *current =first;
        flight *tmp=nullptr;
        string temp;
         if(first ==nullptr)
         {
            return;
         }

         else
         {
            while(current != nullptr)
            {

                tmp = current ->getNextflight();

                while(tmp != nullptr)
                {

                    if(current->get_time() > tmp->get_time()) {
                        temp = current->get_time();
                        current->get_time() = tmp->get_time();
                        tmp->get_time() = temp;
                    }
                    tmp = tmp->getNextflight();
                }
                current = current->getNextflight();
            }
        }
    }
    void print(int band)
    {
        int end , start;
        if(band==0){
            start=1;
            end=5;
        }
        else{
            start=band;
            end=band;
            cout<<endl<<"Runway "<<band;
        }
        cout<<"\n-----------------------------------------------------------------------------------------------\n";
        printf("%-10s | %-10s | %-10s | %-15s | %-10s | %-10s | %-10s | \n" ,"Time" ,
                                                  "Type" , "Model" , "flight_number" ,
                                                        "id" , "passengers" ,"runway");
        cout<<"-----------------------------------------------------------------------------------------------\n";



            for(int j=1; j<=48; j++){

                for(int i=start; i<=end; i++){

                    if(runways[i][j] != 0)
                        {

                         flight* current = first;

                           while (current != NULL)
                             {
                                if (current->get_id() ==runways[i][j])
                                 {

                                    printf("%-10s | %-10s | %-10s | " , current->get_time().c_str()  ,
                                            current->get_type().c_str() , current->get_model().c_str());

                                    printf( "%-15d | %-10d | %-10d | %-10d | \n" , current->get_flight_number() ,
                                            current->get_id() , current->get_passengers() , current->get_runway());
                                    cout<<"-----------------------------------------------------------------------------------------------\n";

                                 }
                                current = current->getNextflight();
                             }

                         }
                     }
                }
    }

    void Delete(int f_n)
    {
         Delete_from_runway(f_n);

         flight * current = first;
         flight * tmp;

         if(current->get_flight_number()==f_n)
            first=first->getNextflight();

         else
            {
                while(current->get_flight_number()!=f_n)
                {
                    tmp=current;
                    current=current ->getNextflight();
                }

             tmp->setNextflight(  current ->getNextflight());
             delete current;
            }
         number_of_flights--;
    }
    void Delete_from_runway(int f_n)
    {
       int id;
       flight* current = first;

         while (current != NULL)
          {
             if (current->get_flight_number() == f_n)
               id=current->get_id();

              current = current->getNextflight();
          }

          for(int i=1; i<=5; i++)
             for(int j=1; j<=48; j++)
               if(runways[i][j]==id)
                  runways[i][j]=0;


    }
    bool searchById(int key )
    {

      flight* current = first;

      while (current != NULL)
      {
        if (current->get_id() == key)
            return false;

        current = current->getNextflight();
      }

      return true;
    }

    flight * searchByFlightNumber(int f_n)
    {

      flight* current = first;

        while (current != NULL)
        {

          if (current->getNextflight()->get_flight_number() == f_n)
              return current;

            current = current->getNextflight();
        }

    }
    int Band(string model , string time , int id)
    {
        int band;
        string name;

        if(model == "A380" || model == "747" || model == "777")//5
            band=5;

        else if(model == "A350" || model == "A340-600")//4
            band=4;

        else if(model == "A300" || model == "A310" || model=="757")//3
            band=3;

        else if(model == "A319" || model == "A320" || model == "A321" )//2
            band=2;

        else if( model == "727" || model == "737" || model == "MAX 737")//1
            band=1;

        check(band , time , id);

    }
    int check(int band , string time , int id)
    {
        char *str1 , *str2 , *c;
        int i  , j , t , hour , minute , t1 , run , counter=0;

        c = const_cast<char*>(time.c_str());
        str1=strtok( c , ":");
        str2=strtok(NULL , "");
        strcat(str1,str2);
        t = atoi(str1);

        hour= t/100;
        minute= t%100;

        t1 = hour*2 + ( minute >= 30 ? 1 : 0 );


        for(i=band; i<=5; i++)
        {
          if(runways[i][t1]==0)
          {
             runways[i][t1]=id;
             run=i;
             break;
          }

        }

         bool flag=false;

         if( i > 5 )
         {
            while( 1 )
             {
                 counter++;
                   for(j=band; j<6; j++)
                      if(runways[j][t1+1]==0)
                      {
                        runways[j][t1+1]=id;
                        run=j;
                        t1+=1;
                        flag=true;
                        break;
                      }
                   if(flag)
                     break;

                 t1+=1;
            }
         }

       int final_hour= hour + (counter*30 + minute)/60;
       int final_minute= (counter*30 + minute)%60;

       string final_time= to_string(final_hour);
       final_time.append(":");
       final_time.append(to_string(final_minute));

       airplane_size[final_time]=run;

    }
    flight *get_first()
    {
        return first;
    }
    int get_size()
    {
        return number_of_flights;
    }
    void destroy(){

        flight *tmp=first;
        while(tmp != nullptr){
            flight *tp= tmp;
            tmp=tmp->getNextflight();
            delete tp;
        }
        this->number_of_flights=0;
        this->first=nullptr;

    }
};

int main()
{
    int num , f_n , band;
    Airport x;
    flight y();
    cout<<"**   **  **** **    **    **  ****   **      ***   *****    **     **  **** \n";
    cout<<"**   **   **   **   **   **   **     **    **     *     *   ** * * **  **\n";
    cout<<"*******   **    **  **  **    ***    **    **     *     *   **  *  **  ***\n";
    cout<<"**   **   **     ** ** **     **     **    **     *     *   **     **  **\n";
    cout<<"**   **  ****     **  **      ****   *****   ***   *****    **     **  ****\n";

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
            x.insert("register");
            break;
          case 2:
            x.insert("add");
            break;
          case 3:
            cout<<"Please enter flight number : ";
            cin>>f_n;
            x.Delete(f_n);
            break;
          case 4:
            x.sort();
            break;
          case 5:
            cout<<"Please enter number of runway (for all runways enter 0): ";
            cin>>band;
            x.print(band);
            break;
          case 0:
            x.destroy();
            break;
      }

    }while(num!=0);

}
