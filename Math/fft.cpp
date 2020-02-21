
// fft : convolution�� ���ϴµ� nlogn�� �ð����� ����
// f(x), g(x) �� ax^n+bx^(n-1)+cx^(n-2).....+z ��
// f(x)->(dft)->f'(x) �Լ� f�� dft�Ͽ� ��ȯ
// g(x)->(dft)->g'(x) �Լ� g�� dft�Ͽ� ��ȯ
// f'*g'(x) O(n) �ð��� ���� �׳� ���ϸ� �ȴ�! (so easy!!)
// f'*g'(x)->(dft)->f*g(x) �� ����ȯ �ϸ�
// �� �Լ��� ���� O(nlogn)�� ����
// ���� dft�� O(n^2)�� �ɸ����� fft�� ����ϸ� O(nlogn)�� ���� 
//
// convolution 
// c[i] = sigma(0<=j<=i)(a[j]*b[i-j]) �� ���¸� ����
// c�� convolution�̶�� �Ѵ�.

namespace fft{
    #define sz(v) ((int)(v).size())
    #define all(v) (v).begin(),(v).end()
    typedef complex<double> base;
    const double pi=acos(-1.0);
    void fft(vector <base> &a, bool invert)
    {
        int n = sz(a);
        for (int i=1,j=0;i<n;i++){
            int bit = n >> 1;
            for (;j>=bit;bit>>=1) j -= bit;
            j += bit;
            if (i < j) swap(a[i],a[j]);
        }
        for (int len=2;len<=n;len<<=1){
            double ang = 2*pi/len*(invert?-1:1);
            base wlen(cos(ang),sin(ang));
            for (int i=0;i<n;i+=len){
                base w(1);
                for (int j=0;j<len/2;j++){
                    base u = a[i+j], v = a[i+j+len/2]*w;
                    a[i+j] = u+v;
                    a[i+j+len/2] = u-v;
                    w *= wlen;
                }
            }
        }
        if (invert){
            for (int i=0;i<n;i++) a[i] /= n;
        }
    }
    
    void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res)
    {
        vector <base> fa(all(a)), fb(all(b));
        int n = 1;
        while (n < max(sz(a),sz(b))) n <<= 1;
        //ū�� ������ ��쿡�� a*b= a.size()+b.size()-1 �� ũ�⸦ �����Ƿ� n*=2
        n*=2;
        fa.resize(n); fb.resize(n);
        fft(fa,false); fft(fb,false);
        for (int i=0;i<n;i++) fa[i] *= fb[i];
        fft(fa,true);
        res.resize(n);
        for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
    }
};