int arr;

//1. 꽉찬 집합(n)
int n;
(1<<n)-1;

//2. 원소 추가
int a;
arr |= (1<<a);

//3. 원소의 포함 여부
if(arr & (1<<a))

//4. 원소의 삭제
arr &= ~(1<<a);

//5. 원소의 토글
arr ^= (1<<a);

int b;
//6. 두 집합에 대한 연산
//  6-1 합집합
    a | b;
//  6-2 교집합
    a & b;
//  6-3 a-b의 차집합
    (a &~b);
//  6-4 a와 b를 동시에 포함하지 않은 원소의 집합
    a ^ b;

//7. 집합에 크기 구하기
void bitCount(int x){
    if(x==0)return 0;
    return x%2 + bitCount(x/2);
}

//8. 최소 원소 찾기
arr & -arr;

//9. 최소 원소 지우기
arr & (arr-1);