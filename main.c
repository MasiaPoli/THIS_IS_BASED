#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include <graphics.h>
int main()
{
    struct group *g=new_group();

    if(!g)
    {
        perror("Creation a group");
    }
    while(1)
    {
        printf("If you want to add write 0, age, points and name, if you want to delete, write 1 and index, if you want to see, write 2, if you want to sort, write 3 and number of type - 0 - age, 1 - points, 2 - name, if you want to add from file, write 4 and file's name, if you want to write to file, write 5 and file's name\n");
        printf("If you want to sort in reverse order, write 6 and number of type (0 - age, 1 - points, 2 - name), if you want to see a bar char, write 7 and 0 if you want to see age char, 1 if you want to see points char \n");
        printf("If you want to see a circle char, write 8 and if you want to see age char, write 0, if you want to see points char, write 1. If you want to stop, write 9\n");
        int x;
        scanf("%d", &x);
        int age;
        double point;
        char name[20];
        int index;
        cmp c;
        int y;
        int w=0;
        char fname[20];
        switch(x)
        {
        case 0:
            scanf("%d%lf", &age, &point);
            scanf("%19[^\n]s", name);
            char ch;
            scanf("%c", &ch);
            if(st_add(g, age, point, name))
            {
                perror("Problems with adding a student");
            }
            break;
        case 1:
            scanf("%d", &index);
            if(st_del(g, index))
            {
                perror("Problems with deleting a student");
            }
            break;
        case 2:
            say(g);
            break;
        case 3:
            scanf("%d", &y);
            switch(y)
            {
            case 0:
                c=pointu;
                break;
            case 1:
                c=podoblu;
                break;
            case 2:
                c=postringu;
                break;
            }
            start_heap_sort(g, c);
            break;
        case 4:
            scanf("%s", fname);
            if(add_from_file(g, fname))
            {
                perror("Problems with adding a student from file");
            }
            break;
        case 5:
            scanf("%s", fname);
            fsay(g, fname);
            break;
        case 6:
            scanf("%d", &y);
            switch(y)
            {
            case 0:
                c=apointu;
                break;
            case 1:
                c=apodoblu;
                break;
            case 2:
                c=apostringu;
                break;
            }
            start_heap_sort(g, c);
            break;
            case 7:
                scanf("%d", &x);
                bar_data(g, x);
                break;
            case 8:
                scanf("%d", &x);
                circle_data(g, x);
                break;
        case 9:
            w=1;
            break;
        }
        if(w)
            break;
    }
    destroy(g);
    return 0;
}
