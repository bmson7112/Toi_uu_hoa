#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int n, a[7][7],sm=0,m[7];
//Đọc file sau đó gán vào mảng a[][]
void docfile(){ 
 int q,p;
 ifstream dothi ("D:\\BTVN\\BuiMinhSon_2\\dothi.txt");// Mở file text miêu tả các đỉnh trong đồ thị sử dụng đường dẫn tới file đó
 if (dothi.is_open())
 {
 dothi >> n;
 // Sử dụng vòng lặp while để đọc 
 while (!dothi.eof()) 
 {
 dothi >> q;
 dothi >> p;
 a[q][p]=9;
 a[p][q]=9;
 }
 dothi.close();
 }
 else cout << "Khong mo duoc file";
}
// Xử lý để đưa ra kết quả vào mảng m[]
void xuly(){ 
 int kt;
 for(int i=1;i<=n;i++)
 if(!m[i]) {
 sm++; //Đếm số màu
 m[i]=sm;
 for(int j=i+1;j<=n;j++) //kiểm tra xem những đỉnh nào có thể gán bằng màu sm
nua khong
 if((a[i][j]==0)&&(m[j]==0)){
 kt=1;
 for(int k=i+1;k<j;k++)
 if((a[k][j]==1)&&(m[i]==m[k])){
 kt=0;
 break;
 }
 if(kt==1) m[j]=sm;
 }
 }
}
void xuatkq(){ //In kết quả ra màn hình
 for(int i=1;i<=sm;i++){
 cout << "Mau " << i << ": ";
 for(int j=1;j<=n;j++) if(m[j]==i) cout << j << " ";
 cout << endl;
 }
}
int main(){
 docfile();
 cout << n << endl;
 for(int i=1;i<=n;i++){ 
 for(int j=1;j<=n;j++) cout << a[i][j] << " ";
 cout << endl;
 }cout << endl;
 xuly();
 xuatkq();
  return 0;
}