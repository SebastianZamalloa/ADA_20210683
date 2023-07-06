#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una tarea
struct Tarea {
    int duration;
    int beneficio;
};

// Función para comparar tareas según su tiempo de finalización
bool comparar(Tarea a, Tarea b) {
    return a.beneficio > b.beneficio;
}

int getMaxDuration(vector<Tarea>& tareas)
{
    int max = 0;
    for(auto i:tareas)
    {
        if(i.duration >= max)
            max = i.duration;
    }return max;
}

template<typename T>
bool isFullVector(vector<T> v, int n)
{
    for(int i = 0; i<n;i++)
    {
        if(v[i].beneficio == 0)
            return false;
    }
    return true;
}

// Función que implementa el algoritmo de planificación de tareas
vector<Tarea> planificacionTareas(vector<Tarea> tareas) {
    int n = tareas.size();
    vector<Tarea> dp(getMaxDuration(tareas),{0,0});
    for(int i = 0; i<n; i++)
    {
        if(dp[tareas[i].duration-1].beneficio == 0){
            dp[tareas[i].duration-1].beneficio = tareas[i].beneficio;
            dp[tareas[i].duration-1].duration = tareas[i].duration;
        }
        else
        {
            for(int j = tareas[i].duration-2; j >=0; j--)
            {
                if(tareas[i].duration-1 >= j && dp[j].beneficio == 0){
                    dp[j].beneficio = tareas[i].beneficio;
                    dp[j].duration = tareas[i].duration;
                }
            }
        }
        if(isFullVector<Tarea>(dp,getMaxDuration(tareas)))
            break;
    }
    return dp;
}

int main() {
    // Ejemplo de uso
    vector<Tarea> tareas = {
        {3, 20},   
        {1, 15},    
        {1, 10},   
        {3, 7}, 
        {1, 5},     
        {3,3}    
    };

    sort(tareas.begin(), tareas.end(), comparar);

    vector<Tarea>maxBeneficio = planificacionTareas(tareas);
    for(auto i:maxBeneficio){
        cout<<i.beneficio<<endl;
        cout<<i.duration<<endl;
        cout<<endl;
    }
    return 0;
}
