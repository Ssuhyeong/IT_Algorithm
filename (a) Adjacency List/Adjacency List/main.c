#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 9
#define TRUE 1

typedef struct Node {
    int ver;
    struct Node* link;
}Node;

typedef struct Graph {
    int n;
    Node* adj_list[MAX_VERTICES];
}Graph;

// Graph 생성
void CreateGraph(Graph *g) {
    int v;
    g -> n = 0;
    for(v = 1;v < MAX_VERTICES; v++)
    {
        g -> adj_list[v] = NULL;
    }
}

// 정점 삽입
void insert_vertex(Graph *g, int v)
{
    if((g->n) + 1 > MAX_VERTICES) {
        printf("그래프 최대 정점의 개수가 초과했습니다. ");
        return;
    }
    g -> n++;
}

// 간선 삽입 < 인접 리스트 >
void insert_edge(Graph *g, int u, int v)
{
    Node* node;
    if(u >= g->n || v >= g->n) {
        printf("정점 번호 삽입 오류로 취소");
        return;
    }
    if(g -> adj_list[u] == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node -> ver = v;
        node -> link = g -> adj_list[u];
        g -> adj_list[u] = node;
    }
    else {
        node = g -> adj_list[u];
        while (node -> link != NULL)
            node = node -> link;
        node -> link = (Node*)malloc(sizeof(Node));
        node -> link -> ver = v;
        node -> link -> link = NULL;
    }
}

// <추가> 인접리스트 출력
void print_adj_list(Graph *g) {
    printf("Graph 인접 리스트 출력 \n");
    for (int i = 1;i < g -> n;i++)
    {
        Node *p = g -> adj_list[i];
        printf("Vertex [ %d ] ", i);
        while(p != NULL) {
            printf("-> %d ", p -> ver);
            p = p -> link;
        }
        printf("\n");
    }
}

// 과제의 그림과 같게 하기 위해서 노드 1 ~ 8 의 그래프를 표현했습니다.

int main() {
    Graph *g;
    g = (Graph*)malloc(sizeof(Graph));
    CreateGraph(g);
    for(int i = 0;i <= 8;i++)
        insert_vertex(g, i);
        
    insert_edge(g, 1, 2);
    insert_edge(g, 1, 3);
    insert_edge(g, 1, 4);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 1);
    insert_edge(g, 3, 2);
    insert_edge(g, 3, 4);
    insert_edge(g, 3, 5);
    insert_edge(g, 4, 1);
    insert_edge(g, 4, 3);
    insert_edge(g, 4, 6);
    insert_edge(g, 4, 7);
    insert_edge(g, 5, 3);
    insert_edge(g, 6, 4);
    insert_edge(g, 6, 7);
    insert_edge(g, 6, 8);
    insert_edge(g, 7, 4);
    insert_edge(g, 7, 6);
    insert_edge(g, 7, 8);
    insert_edge(g, 8, 6);
    insert_edge(g, 8, 7);
    
    print_adj_list(g);
    
    free(g);
    return 0;
}
