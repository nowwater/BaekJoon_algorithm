// ������佺 ������
// ax+by=c
// (a,b)|c �� ��쿡�� �ذ� ���� (�ʿ��������)
// ax+by=(a,b)�� �ظ� x0,y0��� �ϰ�
// c=k*(a,b) ��� �� ��
// �ʱ��ش� k*x0, k*y0�̴�
// �Ϲ��ش� k*x0+b/(a,b), k*y0-a/(a,b) �̴�
//
// Ȯ��� ��Ŭ���� ȣ����
// ax+by=(a,b)��  {(a,b),{x0,y0}} ����
//
// ���� �յ� ������ ax=c(mod b)
// ax+by=c �� �ظ� ���ϸ� ��
typedef long long ll;
pair<ll, pair<ll, ll> > gcd(ll a, ll b){
    ll r, r1, r2;
    ll s, s1, s2;
    ll t, t1, t2;
    r1 = a;
    r2 = b;
    s1 = 1;
    s2 = 0;
    t1 = 0;
    t2 = 1;
    ll q;
    while (r2 > 0){
        q = r1 / r2;
        r = r1 - q*r2;
        r1 = r2;
        r2 = r;
        s = s1 - q*s2;
        s1 = s2;
        s2 = s;
        t = t1 - q*t2;
        t1 = t2;
        t2 = t;
    }
    return{ r1, { s1, t1 } };
}