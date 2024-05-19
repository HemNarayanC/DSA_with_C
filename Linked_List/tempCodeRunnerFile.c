ptrThis=header;
        while (ptrThis->next!=NULL)
        {
            /* code */
            ptrThis=ptrThis->next;
        }
        ptrThis->next = newNode;
        newNode->prev = ptrThis;
        printf("Inserted at the end.\n");