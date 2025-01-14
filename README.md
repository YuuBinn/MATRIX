# 연속행렬 곱셈 알고리즘

## 연속행렬 곱셈이란?
연속행렬이 주어졌을 때, 행렬의 곱셈 중 가장 최소의 연산을 수행하는 방법을 찾는 알고리즘이다. 이 알고리즘은 어떤 순서로 행렬을 곱할 지 결정하는 알고리즘이다.


만약 A,B,C,D,E 행렬이 있다면 다음과 같은 형태로 구성될 수 있다.

```
(AB)(CD)E=(ABC)(DE)=....
```

행렬을 어떤 순서로 곱하든 결과는 같다. 결과는 같더라도 연산과정을 최소한으로 줄이는 방식을 찾아야 된다.


만약 A가 10X25, B가 25X5, C가 5X30이면 

연산횟수는 
``` 
(AB)C=(10X25X5)+(10X5X30)=2750
A(BC)=(25X5X30)+(25X30X10)=11250
```
(AB)C 방식이 연산횟수가 2750으로 최소이므로 선택




## 연속행렬곱셈의 각 함수 기능
전체 소스 코드는 저장소의 cpp파일에 있습니다.  
 + java로 구현한 소스코드
``` java
package dynamic;

import java.util.Scanner;

public class matrixchain {
    private static final int INF = Integer.MAX_VALUE / 2;

    private static int[][] MATRIX() { // 입력받을 행렬의 배열 생성

        return new int[3][501];
    }

    private static int[][] Dynamic_Programming_place() {

        return new int[501][501];//동적알고리즘 배열
    }


    private static void make_MATRIX(Scanner scanner, int[][] matrix, int num) { // 배열 입력

        for (int i = 1; i <= num; i++) {
            System.out.println(i + "번째 행,열 입력");
            matrix[0][i] = scanner.nextInt();
            matrix[1][i] = scanner.nextInt();
        }
    }

    private static int getNum(Scanner scanner) {
        System.out.println("행렬개수 입력: ");
        int num = scanner.nextInt();
        return num;
    }

    private static void MATRIXCHAIN(int[][] matrix, int num, int[][] DP) {
        for(int i = 1; i <= num; i++)
            DP[i][i] = 0; //

        for(int l = 1; l <= num -1; l++) //l:부분문제 크기조절 인덱스 ex) num이 4면, l은 3->2->1까지
        {
            for(int i = 1; i <= num - l; i++)
            {
                int j = i + l;
                DP[i][j] = INF;
                for(int k = i; k <= (j-1); k++)
                {
                    int temp = DP[i][k] + DP[k+1][j] + (matrix[0][i] * matrix[1][k] * matrix[1][j]);

                    if(temp < DP[i][j]) {
                        DP[i][j] = temp;
                        System.out.println(i + "행" + j + "열: " + DP[i][j]);
                    }
                    else System.out.println("*"+i + "행" + j + "열: " + temp + "은 탈락*");
                }
            }

        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[][] matrix = MATRIX(); // 입력할 행렬 선언

        int num = getNum(scanner); //행렬 개수 입력

        make_MATRIX(scanner, matrix, num);//행렬 입력

        int[][] DP = Dynamic_Programming_place(); // 동적알고리즘이 돌아갈 공간의 행렬 선언

        MATRIXCHAIN(matrix, num, DP); // 동적알고리즘 실행

        System.out.println("행렬의 최소 곱셈 횟수 : " + DP[1][num]);
    }

}
```



## 작동방식
예를들어 A 행렬이 5X15 B 행렬이 15X8 C행렬이 8x12 D행렬이 12X12이다.







ex)


dp|1|2|3|4|
---|---|---|---|---|
1|0||||
2||0|||
3|||0||
4||||0|

ex2) 교재 예시  
A 행렬 : 10X20, B 행렬: 20X5, C 행렬: 5X15, D행렬 : 15X30

dp |A   |B   |C   |D   |
---|----|----|----|----|
A  |0   |1000|1750|4750|
B  |    |0   |1500|5250|
C  |    |    |0   |2250|
D  |    |    |    |0   |   

<예시 작동 결과>  
![image](https://user-images.githubusercontent.com/101345032/162639704-7c6134f2-3622-4fc9-95fc-c35978536d91.PNG)


+ 동적 알고리즘의 시간 복잡도는 삼중 for문의 사용으로 __O(n³)__ 이다.


## 맡은일과 느낀점

### 201901662/김어진

교재의 코드를 바탕으로 코드를 직접 구현해보고, '행렬이 입력'받고 '최소값이 아닌 행열의 곱셉을 탈락이라고 표현'할 수 있도록 추가적으로 구현했습니다. 덧붙여서 코드에 교재의 예시를 넣어 실행시킨 결과도 첨부했습니다. 직접 코드를 구현하며 동적 알고리즘의 부분문제에 대하여 확실히 이해할 수 있었고, 곧 다가올 2학기때 전기자기학의 행렬부분에서 유용하게 사용할 수 있겠다고 생각했습니다. 아쉬운 점은 최소 곱셈 횟수는 구할 수 있었으나, 최소 곱셈 횟수를 구하는 식을 구현하지 못한 점입니다.("(AXB) X (CXD)"가 최소 곱셈 횟수의 식이라는 것을 구할 수 있도록 구현하지는 못했습니다.)