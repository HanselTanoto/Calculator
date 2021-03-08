// Hansel Valentino Tanoto - 16520399 - STEI
# include <iostream>
using namespace std;

// Mendefinisikan Fungsi Penjumlahan
float add(float a, float b){
	return a+b;
}
// Mendefinisikan Fungsi Pengurangan
float sub(float a, float b){
	return a-b;
}
// Mendefinisikan Fungsi Perkalian
float mul(float a, float b){
	return a*b;
}
// Mendefinisikan Fungsi Pembagian
float div(float a, float b){
	return a/b;
}
// Mendefinisikan Fungsi Pemangkatan
float pow(float a, int b){
    float result = 1;
    // Loop untuk mengalikan a sampai sebanyak b kali
	for (int i = 0; i < b; i++){
		result *= a;
	}
	return result;
}
// Mendefinisikan Fungsi Polinomial
float f(float x, int m, float C[]){
    float result = 0;
    for (int i = 0; i <= m; i++){
		result += C[i] * pow(x,m-i);
	}
	return result;
}
// Mendefinisikan Fungsi Menghitung Integral Dengan Jumlah Riemann Trapesium
float intg (float a, float b, int n, int m, float C[]){
    float dx = (b-a)/n;                     // Panjang interval : tinggi trapesium
    float result = 0;
    // Loop untuk menjumlahkan luas dari partisi 1 sampai partisi ke n
    for (int i = 0; i < n; i++){
        float x1 = a + i * dx;              // x_i 
        float x2 = a + (i + 1) * dx;        // x_(i+1)
        float y1 = f(x1,m,C);               // y_i     : sisi sejajar ke-1 trapesium
        float y2 = f(x2,m,C);               // y_(i+1) : sisi sejajar ke-2 trapesium
        result += 0.5 * (y1 + y2) * dx;
    }
    return result;
}
// PROGRAM UTAMA
int main(){
    cout << "----------------CALCULATOR----------------" << endl;
	bool Continue = true;
    // Loop program kalkulator
    do{
        string op;
        float a, b;
        // Menampilkan menu dan meminta input operator
        cout << "MENU:\n" 
                "1. Addition       (Type 'add'  or 'Add' )\n"
                "2. Subtraction    (Type 'sub'  or 'Sub' )\n"
                "3. Multiplication (Type 'mul'  or 'Mul' )\n"
                "4. Division       (Type 'div'  or 'Div' )\n"
                "5. Power          (Type 'pow'  or 'Pow' )\n"
                "6. Integral       (Type 'intg' or 'Intg')\n"
                "Choose Operation: ";
	    cin >> op;
        // Untuk operator integral
	    if (op == "intg" || op == "Intg"){
		    int n, m;
			string func = {};
            // Input untuk fungsi yang akan diintegralkan
		    cout << "- Integral of Polynomials -" << endl;
			cout << "  Degree of Polynomial: ";
		    cin >> m;
            float C[m];
			for (int i = 0; i <= m; i++){
				cout << "  Coefficient of x^" << m-i << ": ";
				cin >> C[i];
				if (m-i > 0){
					func += to_string(C[i]) + " x^" + to_string(m-i) + " + ";
				}
				else{
					func += to_string(C[i]) + " = 0";
				}
			}
			cout << " Function: " << func << endl;
            // Input untuk variabel integral
            cout << "Initial Limit: ";
		    cin >> a;
		    cout << "Final Limit: ";
		    cin >> b;
		    cout << "Number of Subinterval: ";
		    cin >> n;
		    cout << "RESULT: " << intg(a,b,n,m,C) << endl;                             // Memanggil fungsi intg
	    }
        // Untuk operator pemangkatan
	    else if (op == "pow" || op == "Pow"){
		    int b;
		    cout << "Base Number: ";
		    cin >> a;
		    cout << "Exponent: ";
		    cin >> b;
		    cout << "RESULT: " << a << " ^ " << b << " = " << pow(a,b) << endl;        // Memanggil fungsi pow
	    }
        // Untuk operator penjumlahan
		else if (op == "add" || op == "Add"){
		    cout << "First Number: ";
		    cin >> a;
		    cout << "Second Number: ";
		    cin >> b;
            cout << "RESULT: " << a << " + " << b << " = " << add(a,b) << endl;        // Memanggil fungsi add
	    }
        // Untuk operator pengurangan
	    else if (op == "sub" || op == "Sub"){
		    cout << "First Number: ";
		    cin >> a;
		    cout << "Second Number: ";
		    cin >> b;
            cout << "RESULT: " << a << " - " << b << " = " << sub(a,b) << endl;        // Memanggil fungsi sub
	    }
        // Untuk operator perkalian
	    else if (op == "mul" || op == "Mul"){
		    cout << "First Number: ";
		    cin >> a;
		    cout << "Second Number: ";
		    cin >> b;
            cout << "RESULT: " << a << " x " << b << " = " << mul(a,b) << endl;        // Memanggil fungsi mul
	    }
        // Untuk operator pembagian
	    else if (op == "div" || op == "Div"){
		    cout << "First Number: ";
		    cin >> a;
		    cout << "Second Number: ";
		    cin >> b;
            cout << "RESULT: " << a << " : " << b << " = " << div(a,b) << endl;        // Memanggil fungsi div
	    }
        // Untuk operator yang tak terdefinisi
	    else{
		    cout << "\n-Invalid Operation-" << endl;
	    }
        // Meminta input untuk melanjutkan program
        char input;
        cout << "\nDo you want to continue? Y/N: ";
	    cin >> input;
        if(input != 'Y' && input != 'y'){
            Continue = false;
        }
    }
    while(Continue);
}
