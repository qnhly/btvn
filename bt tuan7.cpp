#include<iostream>
using namespace std;

class Data{
private:
    int namsinh;
    int soluong;
public:
    
    Data()= default;
    Data(int nam, int so) : namsinh(nam), soluong(so) {}

    int get_namsinh(){return namsinh;}
    int get_soluong(){return soluong;}
    void set_namsinh(int namsinh){this-> namsinh = namsinh;}
    void set_soluong(int soluong){this-> soluong = soluong;}

    ~ Data() {}
};


int main(){
    int n;
    cout<<"so dan can nhap: ";  cin>>n;
    Data* dan = new Data[n];    //cap phat dong cho mang
    for(int i=0;i<n;i++){
        int nam, so;
        cout<<"i = "<<i+1<<endl;
        cin>> nam >> so;
        dan[i].set_namsinh(nam);
        dan[i].set_soluong(so);
    }

    //sapxep tu tang dan
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(dan[i].get_soluong()>dan[j].get_soluong()){  //swap ca phan tu
                Data tg=dan[i]; dan[i]=dan[j]; dan[j]=tg;
        
            }
        }
    }

    cout<<"Nam co so luong nguoi sinh ra la lon nhat la: "<<dan[n-1].get_namsinh()<<endl;
    cout<<"Nam co so luong nguoi sinh ra la be nhat la: "<<dan[0].get_namsinh()<<endl;


    delete[] dan;
    return 0;

}