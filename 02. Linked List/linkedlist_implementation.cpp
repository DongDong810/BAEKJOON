#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; // 새로운 원소가 들어갈 수 있는 인덱스 (0번지는 시작점을 나타내기 위한 dummy node)

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur] << " ";
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert(int addr, int num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[unused]] = unused; // 맨 뒤에 추가하는 경우 주의
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr]; // 0번지 시작 원소 있어서 따로 예외처리 필요 없음
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr]; // 맨 뒤 원소 삭제하는 경우 주의
    dat[addr] = -1;
    nxt[addr] = -1;
    pre[addr] = -1;
}

void insert_test()
{
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test()
{
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main() 
{  
    // -1로 초기화 (원소가 존재하지 않음을 의미)
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    insert_test();
    erase_test();
}