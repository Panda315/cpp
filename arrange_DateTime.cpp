#include <iostream>
using namespace std;

class Date
{
    protected:
        int year,month,day;

    public:
        Date() : year(0),month(0),day(0) {}
       // Date (int yearO,int monthO,int dayO) : year(yearO),month(monthO),day(dayO) {}

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
        // Time(int hourO,int minO,int secO) : hour(hourO),min(minO),sec(secO) {}

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
    
    bool operator > (DateTime &temp)
    {
        /* if(year>=temp.year || month>=temp.month || day>=temp.day || hour>=temp.hour || min>= temp.min || sec>=temp.sec)
            return true;

        else 
            return false;
        */

       if(year>temp.year)
            return true;
        else if(year<temp.year)
            return false;
        else 
        {
            if(month>temp.month)
                return true;
            else if(month<temp.month)
                return false;
            else
            {
                if(day>temp.day)
                    return true;
                else if(day<temp.day)
                    return false;
                else
                {
                    if(hour>temp.hour)
                        return true;
                    else if(hour<temp.hour)
                        return false;
                    else
                    {
                        if(min>temp.min)
                            return true;
                        else if(min<temp.min)
                            return false;
                        else
                        {
                            if(sec>temp.sec)
                                return true;
                            else    
                                return false;
                        }
                    }
                }
            }
        }
    } 

    void print()
    {
        cout << "Date : " << year << "/" << month << "/" << day << endl;
        cout << "Time : " << hour << "/" << min << "/" << sec << endl << endl;
    }
};

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

    cout << "\nDate and Time on ascending order : " << endl;
    for(int i=0;i<size;i++)
    {
        datetime[i].print();
    }
    
    



}