#include <iostream>
#include <vector>
#include <fstream>


using namespace std;


void nhapdulieu(int&, vector<vector<int>> &);
void xuatdulieu(int , vector<int> );
void t_bac(int , vector<vector<int>>, vector<int>&);
int check_hight(int , vector<int>);
void check_bac(int , int , vector<vector<int>> , vector<int>&);
int check_mau(int , int, vector<vector<int>> , vector<int>);

void to_mau(int , vector<vector<int>> , vector<int>&);

int main()
{
    vector<vector<int>> dothi;
    vector<int> ketqua(0);
    int size_z;

    nhapdulieu(size_z, dothi);
    to_mau(size_z, dothi, ketqua);

    for (int i = 0; i < size_z; i++){ //show ket qua ra man hinh
        cout << "(" << char(i+65) << "," << ketqua[i] << ") ";
    }

    xuatdulieu(size_z, ketqua);
    return 0;
}

void nhapdulieu(int& size_z, vector<vector<int>> &dothi)
{
    ifstream infile;
    infile.open("input.txt");
    infile >> size_z;
    for (int i = 0; i < size_z; i++){
        vector<int> arr(size_z,0);
        for (int j = 0; j < size_z; j++){
            infile >> arr[j];
        }
        dothi.push_back(arr);
    }
}

void xuatdulieu(int n, vector<int> arr)
{
    ofstream outfile;
    outfile.open("output.txt");
    for (int i = 0; i < n; i++){
        outfile << "(" << i << "," << arr[i] << ") ";
    }
}

void t_bac(int size_z, vector<vector<int>> dothi, vector<int> &bac)
{
    for (int i = 0; i < size_z; i++){
        int count = 0;
        for (int j = 0; j < size_z; j++){
            if(dothi[i][j]) {
                count ++;
            }
        }
        bac.push_back(--count);
    }
}

int check_hight(int size_z, vector<int> bac)
{
    int hight = 0;
    for (int i = 1; i < size_z; i++){
        if (bac[hight] < bac[i]) {
            hight = i;
        }
    }
    return hight;
}

void check_bac(int size_z, int vt_hight, vector<vector<int>> dothi, vector<int>& bac)
{
    for (int i = 0; i < size_z; i++) {
        if ((dothi[vt_hight][i]) && (vt_hight != i)) {
            bac[i] --;
        }
    }
}

int check_mau(int size_z, int vt_hight, vector<vector<int>> dothi, vector<int> mau)
{
    int count;
    vector<bool> c_mau(size_z, 0);
    for (int i = 0; i < size_z; i++){
        if ((dothi[vt_hight][i]) && (vt_hight != i)){
            if(mau[i]){
                c_mau[--mau[i]] = 1;
            }
        }
    }

    for (int i = 0; i < size_z; i++){
        if (!c_mau[i]) {
            return ++i;
        }
    }
}

void to_mau(int size_z, vector<vector<int>> dothi, vector<int> &ketqua)
{
    vector<int> bac(0);
    int vt_hight;
    t_bac(size_z, dothi, bac);
    vector<int> mau(size_z, 0);

    for (int i = 0; i < size_z; i++){
        vt_hight = check_hight(size_z, bac);
        mau[vt_hight] = check_mau(size_z, vt_hight, dothi, mau);
        bac[vt_hight] = -1;
    }

    for (int i = 0; i < size_z; i++){
        ketqua.push_back(mau[i]);
    }
}
