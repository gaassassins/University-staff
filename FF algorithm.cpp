#include "stdio.h"
#include "iostream"
 
using namespace std;
 
#define WHITE 0
#define GREY 1
#define BLACK 2
 
int n,e;
int capacity[100][100], 
 flow[100][100],  // матрица потока
 color[100],    
 pred[100];  // массив пути
 int head, tail;  
 int q[102];      // очередь с номерами вершин входящих в неё

 int min(int x, int y)
{
  if (x < y)
    return x;
  else
    return y;
}
void enque(int x) 
{
  q[tail] = x;     
  tail++;          
  color[x] = GREY; // вершина помечена
}
int deque() // убрать вершину из очереди
{
  int x = q[head]; 
  head++;           
  color[x] = BLACK; // в вершину больше не заходить
  return x;         
}

int bfs(int start, int end) // поиск в ширину
{
  int u,v;
  for( u = 0; u < n; u++ )
    color[u]=WHITE;   
 
  head=0;   
  tail=0;   
  enque(start);      // вступили на первую вершину
  pred[start]= -1;   
  while(head!=tail)  // пока хвост не совпадёт с головой
  {
    u=deque();       // вершина которая помечена черным
    for( v = 0; v < n; v++ ) 
    {
     // если не пройдена и не заполнена
     if(color[v] == WHITE && (capacity[u][v]-flow[u][v]) > 0) {
       enque(v);  // переходим в другую вершину
       pred[v]=u; // обновляем наш путь
     }
    }
  }  
  if(color[end] == BLACK) 
    return 0;
  else return 1;
}

int max_flow(int source, int stock) // максимальный поток
{
  int i,j,u;
  int maxflow=0;            
  for( i = 0; i < n; i++ )  
    {
      for( j = 0; j < n; j++)
      flow[i][j]=0;
    }
  while(bfs(source,stock) == 0) // пока путь не равен нулю
    {
      int delta=10000;
      for(u = n-1; pred[u] >= 0; u=pred[u]) // ищем минимальный поток
      {
        delta=min(delta, ( capacity[pred[u]][u] - flow[pred[u]][u] ) );
      }
      for(u = n-1; pred[u] >= 0; u=pred[u]) // по форду-фалкерсону
      {     
        flow[pred[u]][u] += delta; 
        flow[u][pred[u]] -= delta; 
      }
      maxflow+=delta; // максимальный поток увеличиваем
    }
  return maxflow;
}

int main()
{
  freopen ("input.txt", "r", stdin); 
  cin >> n;
  cout << "N: " << n << endl;  
  int i,j;
  for( i = 0; i < n; i++ )
    {
      for( j = 0; j < n; j++ )
        cin >> capacity[i][j];
    }
 
  cout << "Max flow: " << max_flow(0,n-1) << endl;
  
  return 0;
}