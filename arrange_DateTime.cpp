// Write a class for English Date consisting of Year, month and day. 
// Write another class Time which have data members hour, minute and second. 
// Derive a class DateTime to hold date and time values. Ask user to input datetime value and display. 
// Write suitable default and parameterized constructors for each class as required.

// Create an array of DateTime values and sort them in ascending or descending order as per the user request.
//  Overload '>' operator to compare two DateTime objects.

// Author - Prashant Shrestha

#include <iostream>
#include <string>

using namespace std;

class Date
{
    protected:
        int year,month,day;

    public:
        Date() : year(0),month(0),day(0) {}
        Date (int yearO,int monthO,int dayO) : year(yearO),month(monthO),day(dayO) {}

        void Date_input()
        {
            cout << "Year : " ;
            cin >> year; 
            cout << "Month : ";
            cin >> month ;
            cout << "Day : ";
            cin>> day;
        } 
};

class Time 
{
    protected:
        int hour,min,sec;
    
    public:
        Time():hour(0),min(0),sec(0) {}
        Time(int hourO,int minO,int secO) : hour(hourO),min(minO),sec(secO) {}

        void Time_input()
        {
            cout << "\nHour : ";
            cin>> hour;
            cout << "Minutes : ";
            cin >> min;
            cout << "Seconds : ";
            cin >> sec;
        }
};


class DateTime : public Date,public Time
{
    public:
    DateTime() : Date(),Time() {}
    DateTime(int y,int mo,int d,int hr,int mi,int s) : Date(y,mo,d),Time(hr,mi,s) {}


    bool datetime_checker();
    bool operator > (DateTime &temp)    //operator overloading 
    {                                   //checking for recent date among two date and time
        string date1 = to_string(year) + to_string(month) + to_string(day);
        string time1 = to_string(hour) + to_string(min) + to_string(sec);
        string date2 = to_string(temp.year) + to_string(temp.month) + to_string(temp.day);
        string time2 = to_string(temp.hour) + to_string(temp.min) + to_string(temp.sec);
    
        if(stoi(date1)>stoi(date2))
        {
            return true;
        }

        else if(stoi(date1)==stoi(date2) && stoi(time1)>stoi(time2))
        {
            return true;
        }

        else 
            return false;
    } 

    void print()
    {
        cout << "Date : " << year << "/" << month << "/" << day << endl;
        cout << "Time : " << hour << ":" << min << ":" << sec << endl << endl;
    }
};

bool DateTime::datetime_checker()
{
    if(year<1||day<1||month<1||hour<0||min<0||sec<0)        //checking for validity of date and time
    {
        return false;
    }

    else
    {
    if(sec>=60)             //Correcting seconds if required
    {
        do{
            sec=sec-60;
            min++;
        }while(sec>60);
    }
        
    if(min>=60)             //Correcting minutes if required
    {
        do{
            min=min-60;
            hour++;
        }while(min>=60);
    }

    if(hour>=24)             //Correcting hours if required
    {
        do{
            hour = hour - 24;
            day++;
        }while(hour>24);
    }

    check_for_days:         //checking for days in months again if year is increased by the increament of months
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)   //correcting days if required
    {
        if(day>31)
        {
            do
            {
                day=day-31;
                month++;
            }while((day>31) && (month==1||month==3||month==5||month==7||month==8||month==10||month==12));
        }
    }

    if(month==4||month==6||month==9||month==11)
    {
        if(day>30)
        {
            do
            {
                day=day-30;
                month++;
            }while(day>30 && (month==4||month==6||month==9||month==11));
        }
    }

    if(month==2)
    {
        if(day>29)
        {
            do
            {
                day=day-29;
                month++;
            }while(day>29 && month==2);
        }
    }
        
    if(month>12)
    {
        month=month-12;
        year++;
        goto check_for_days;
    }
    return true;
    }
}


int main()
{
    int size;
    cout << "Number of data : ";
    cin >> size;
    DateTime datetime[size];
    for(int i=0;i<size;i++)
    {
        cout << "\nFor Data " << i+1 << ":" << endl;
        datetime[i].Date_input();
        datetime[i].Time_input();
        if(!datetime[i].datetime_checker())
        {
           cout << "\n\n--------------------- You have entered invalid input ---------------------" ;
           return 0; 
        }
    }


    for(int i=0;i<size-1;i++)               //Bubble Sorting
    {
        for(int j=0;j<(size-1)-i;j++)
        {
            if(datetime[j]>datetime[j+1])
            {
                DateTime temp;
                temp = datetime[j];
                datetime[j] = datetime[j+1];
                datetime[j+1] = temp;
            }
        }
    }

    int req;
    cout << "\n\nDo you want the date and time to be represented based on : " << endl;
    cout << "1) Ascending order\n2) Descending order\nEnter the Appropriate number" << endl;
    cin >> req;

    if(req != 1 && req != 2)
    {
        cout << "\nYou have enterd inappropriate number";
        return 0;
    } 

    if(req==1)
    {
        cout << "\nDate and Time on Ascending order : " << endl;
        for(int i=0;i<size;i++)
        {
            datetime[i].print();
        }
    }

    if(req==2)
    {
       cout << "\nDate and Time on Descending order : " << endl;
        for(int i=size-1;i>=0;i--)
        {
            datetime[i].print();
        } 
    }

    return 0;
}