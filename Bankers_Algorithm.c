#include <stdio.h>
void main(){
	int n, m, i, j, k, y = 0, flag;
    int alloc[100][100], max[100][100], avail[100], need[100][100];
    int *f, *ans, ind = 0;

    printf("Enter the number of processes in system: ");
    scanf("%d", &n);

    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    printf("Enter the allocation matrix: \n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the max demand of each process:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources: ");
    for(i=0; i<m; i++){
        scanf("%d", &avail[i]);
    }

    f = (int*)malloc(n*sizeof(int));
    ans = (int*)malloc(n*sizeof(int));


	for (k = 0; k < n; k++) {
		f[k] = 0;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}

	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {
				flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++){
						avail[y] += alloc[i][y];
                    }
					f[i] = 1;
				}
			}
		}
	}

	flag = 1;

	for(i=0;i<n;i++){
        if(f[i]==0){
            flag=0;
            printf("The following system is not safe");
            break;
        }
	}

	if(flag==1){
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++){
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
	}
}
