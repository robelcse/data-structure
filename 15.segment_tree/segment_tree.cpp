#include<stdio.h>
#include<iostream>
#define mx 100001
int arr[mx];
int tree[mx * 3];
using namespace std;
//segment tree implementation in c++


//tree init function
void init(int node, int b, int e){
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}


//query function
int query(int node, int b, int e, int i, int j){
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

//update function
void update(int node, int b, int e, int i, int newvalue){
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}


int main(){

    int n;
    cout<<"please enter the size of array:"<<endl;
    cin >> n;

    cout<<"please enter the elements of array:"<<endl;
    for(int i = 1; i <=n; i++)
        cin>>arr[i];


    init(1, 1, n);
    cout<<"the initial tree is: ";
     for(int i = 1; i < 10; i++){
          cout<<tree[i]<<" ";
     }

     cout<<endl;
    cout <<"the summation from 1-7 is: "<<query(1, 1, n, 1, 7) << endl;
     update(1, 1, n, 1, 8);
     cout <<"the summation from 1-7 is: "<<query(1, 1, n, 1, 7) << endl;

    return 0;
}
