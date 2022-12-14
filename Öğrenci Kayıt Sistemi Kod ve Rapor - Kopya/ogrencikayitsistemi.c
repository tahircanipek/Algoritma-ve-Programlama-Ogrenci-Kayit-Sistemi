
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


FILE *dosya;
struct ogrenci
{
		char ad[50];
		char soyad[50];
		int no;
		int vize, final;
		
		struct ogrenci *next;
};

typedef struct ogrenci node;

node * ekle ( node * head)
{
	dosya=fopen("d:\\sinif.txt","a+");
	if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
	node *ogr = (node *) malloc(sizeof(node));
	printf ("Ogrenci Ad: ");
	 scanf("%s", &ogr -> ad);
	printf ("Ogrenci Soyad: ");
	 scanf("%s", &ogr -> soyad);
	printf ("Ogrenci No: ");
	 scanf("%d", &ogr -> no);
	printf ("Ogrenci Vize Notu: ");
	 scanf("%d", &ogr -> vize);
	printf ("Ogrenci Final Notu: ");
	 scanf("%d", &ogr -> final);
	 
	 fprintf(dosya,"%s %s %d %d %d\n",ogr ->ad, ogr->soyad, ogr->no, ogr->vize, ogr->final);
	 
	 if (head == NULL)
	 {
	 	head = ogr;
	 	head -> next = NULL;
	 	printf("Liste Olusturuldu, ilk ogrenci kaydi yapildi\n");
	 }
	 else
	 {
	 	ogr -> next = head;
	 	head = ogr;
	 	printf("Ogrenci kaydi yapildi\n");
	 }
	 fclose(dosya);
	 return head;
	 
	 
}


node * sil (node *head)
{
	
	bool sonuc = false;
	if(head == NULL)
	{
		printf("Liste bos, silinecek oge yok.\n");
		return head;
		sonuc = true;
	}
	else
	{
		int ogrNo;
		printf("Ogrenci No: %d");
		 scanf("%d",&ogrNo);
		
		if(head -> no == ogrNo && head -> next == NULL)
		{
			free(head);
			head = NULL;
			printf("Listede kalan son ogrenci silindi \n");
			sonuc = true;
		}
		
		else if (head -> no == ogrNo && head -> next != NULL) 
		{
			node *p= head -> next;
			free(head);
			head = p;
			printf("%d numarali ogrenci silindi \n", ogrNo);
			sonuc = true;
			
	    }
	    else
	    {
	    	node *p, *q;
	    	p = head;
	    	q=p;
	    	while (p->next != NULL)
	    	{
	    		if(p -> no == ogrNo)
	    		{
	    			q -> next = p -> next;
	    			free(p);
	    			printf("%d numarali ogrenci silindi \n", ogrNo);
	    			sonuc = true;
	    			break;
				}
				q = p;
				p = p -> next;
			}
			if(p->no==ogrNo)
			{
				q->next = NULL;
				free(p);
				printf("%d numarali ogrenci silindi \n", ogrNo);
				sonuc = true;
			}
		}
		if(!sonuc)
		printf("%d numarali ogrenci listede yok",ogrNo);
	}
	return head;
	
}

node *listele (node * head)
{
	
	 
	 
 
 
	if(head==NULL)
	{
		printf("Liste bos|n");
	}
	else
	{
		node *p;
		p = head;
		while(p!=NULL)
		{
			printf("*************************\n");
			printf(	"Ad: %s Soyad %s No: %d Vize: %d Final:%d \n", p -> ad, p->soyad, p->no, p->vize, p->final); 
		    p = p->next;
		}
	}

	 
	return head;
	
	
}

int main()
{

	int secim;
	node *head= NULL;
	while(1)
	{
		printf("\nOgrenci Kayit Uygulamasi\n");
		printf("1- Ogrenci Ekle\n");
		printf("2- Ogrenci Sil\n");
		printf("3- Ogrenci Listele\n");
		printf("0- Cikis\n");
		scanf("%d", &secim);
		
		switch(secim)
		{
			case 1: head = ekle(head);
			break;
			case 2: head = sil(head);
			break;
			case 3: head = listele(head);
			break;
			case 0: exit(0);
			default: printf("Hatali secim yaptiniz!\n");
		}
		
		
		
	}
	
	
	return 0;
	
}



































