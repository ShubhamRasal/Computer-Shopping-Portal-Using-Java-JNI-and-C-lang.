#include"App.h"
#include<stdlib.h>
#include<dlfcn.h>

JNIEXPORT jint JNICALL Java_App_cacBill(JNIEnv * env,jclass jobj,jintArray arr)
{
    int i, sum = 0;
    jsize len = (*env )->GetArrayLength(env , arr);
    void *p = NULL;
    int (*countTotal)(int [],int) = NULL:

    jint * params = (*env)->GetArrayElements(env,arr,0);

    p = dlopen("G:/Marvellous Infosystems/DON/Project code/ComputerShoppingPortal ",RTLD_LAZY);
    if(!p)
    {
        printf("Unable to load libraray: %s\n",dlerror());
    }
    countTotal = dlsym(p,"countTotal");

    if(countTotal == NULL)
    {
        printf("Unable to get Address of function : %s\n",dlerror());
    }
sum = countTotal (params,len);

(*env)->ReleaseIntArrayElements(env,arr,param,0);
dlclose(p);
return sum;
}