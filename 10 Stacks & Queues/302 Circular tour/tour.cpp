//Function to find starting point where the truck can start to get through
//the complete circle without exhausting its petrol in between.
int tour(petrolPump p[], int n)
{
    //Your code here
    int deficit = 0, start = 0, cal = 0;
    for (int i = 0; i < n; i++)
    {
        cal += p[i].petrol - p[i].distance;
        if (cal < 0)
        {
            start = i + 1;
            deficit += cal;
            cal = 0;
        }
    }
    return (cal + deficit >= 0) ? start : -1;
}