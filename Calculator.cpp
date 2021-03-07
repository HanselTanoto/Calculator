// Hansel Valentino Tanoto - 16520399 - STEI
# include <iostream>
using namespace std;

// Mendefinisikan Fungsi Penjumlahan
void add(float a, float b){
	cout << "Result: " << a << " + " << b << " = " << a+b << endl;
}
// Mendefinisikan Fungsi Pengurangan
void sub(float a, float b){
	cout << "Result: " << a << " - " << b << " = " << a-b << endl;
}
// Mendefinisikan Fungsi Perkalian
void mul(float a, float b){
	cout << "Result: " << a << " x " << b << " = " << a*b << endl;
}
// Mendefinisikan Fungsi Pembagian
void div(float a, float b){
	cout << "Result: " << a << " : " << b << " = " << a/b << endl;
}
// Mendefinisikan Fungsi Pemangkatan
void pow(float a, int b){
    float result = 1;
    // Loop untuk mengalikan a sampai sebanyak b kali
	for (int i = 0; i < b; i++){
		result *= a;
	}
	cout << "Result: " << a << " ^ " << b << " = " << result << endl;
}
// Mendefinisikan Fungsi Yang Akan Diintegralkan
float f(float x){
    return x*x + 2*x + 1;
}
// Mendefinisikan Fungsi Integral
void intg (float a, float b, int n){
    float dx = (b-a)/n;                 // Panjang interval : tinggi trapesium
    float result = 0;
    // Loop untuk menjumlahkan luas dari partisi 1 sampai partisi ke n
    for (int i = 0; i < n; i++){
        float x1 = a + i * dx;          // x_i 
        float x2 = a + (i + 1) * dx;    // x_(i+1)
        float y1 = f(x1);               // y_i     : sisi sejajar ke-1 trapesium
        float y2 = f(x2);               // y_(i+1) : sisi sejajar ke-2 trapesium
        result += 0.5 * (y1 + y2) * dx;
    }
    cout << "Result: " << result << endl;
}

int main(){
    cout << "----------------CALCULATOR----------------" << endl;
	bool Continue = true;
    // Loop program kalkulator
    do{
        string op;
        // Menampilkan menu dan meminta input operator
        cout << "Menu:\n" 
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
		    float a, b;
		    int n;
		    cout << "Function : f(x) = x^2 + 2x + 1" << endl;
            cout << "Initial Limit: ";
		    cin >> a;
		    cout << "Final Limit: ";
		    cin >> b;
		    cout << "Number of Subinterval: ";
		    cin >> n;
		    intg(a,b,n);     // Memanggil fungsi intg
	    }
        // Untuk operator pemangkatan
	    else if (op == "pow" || op == "Pow"){
		    float a; int b;
		    cout << "Number: ";
		    cin >> a;
		    cout << "Power: ";
		    cin >> b;
		    pow(a,b);        // Memanggil fungsi pow
	    }
        // Untuk operator lainnya
	    else{
		    float a, b;
		    cout << "First Number: ";
		    cin >> a;
		    cout << "Second Number: ";
		    cin >> b;
            // Untuk operator penjumlahan
		    if (op == "add" || op == "Add"){
			    add(a,b);    // Memanggil fungsi add
		    }
            // Untuk operator pengurangan
		    else if (op == "sub" || op == "Sub"){
			    sub(a,b);    // Memanggil fungsi sub
		    }
            // Untuk operator perkalian
		    else if (op == "mul" || op == "Mul"){
			    mul(a,b);    // Memanggil fungsi mul
		    }
            // Untuk operator pembagian
		    else if (op == "div" || op == "Div"){
			    div(a,b);    // Memanggil fungsi div
		    }
            // Untuk operator yang tak terdefinisi
		    else{
			    cout << "\n-Invalid Operation-" << endl;
		    }
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