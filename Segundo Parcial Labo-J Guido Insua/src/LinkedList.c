#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Compras.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

//-----------------------------------------------------------------------------------------------

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }

    return this;
}

//-----------------------------------------------------------------------------------------------

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief  Obtiene un nodo de la lista y retorna un puntero al nodo que se encuentra en el índice especificado.
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode; //0

		for(int i=0;i<nodeIndex;i++)
		{
			pNode = pNode->pNextNode;
		}
	}

    return pNode;
}

//-----------------------------------------------------------------------------------------------

/** \brief Agrega y enlaza un nuevo nodo a la lista en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pAnterior = NULL;
    Node* pNuevo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	pNuevo = (Node*)malloc(sizeof(Node)*1);

    	if(nodeIndex == 0)
    	{
    		pNuevo->pNextNode = this->pFirstNode;

    		this->pFirstNode = pNuevo;
    	}
    	else
    	{
			pAnterior = getNode(this, nodeIndex-1);
			if(pAnterior != NULL)
			{
				pNuevo->pNextNode = pAnterior->pNextNode;
				pAnterior->pNextNode = pNuevo;
			}
    	}

    	pNuevo->pElement = pElement;

    	this->size++;

    	returnAux = 0;
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief  Agrega un elemento al final de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this,ll_len(this),pElement);
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado.
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    	}
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Modifica un elemento de la lista, insertando el elemento pasado por puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Elimina un elemento de la lista, en el índice especificado.
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* pAnterior = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
			if(index == 0)
			{
				this->pFirstNode = pNode->pNextNode;
			}
			else
			{
				pAnterior = getNode(this, index-1);
				if(pAnterior != NULL)
				{
					pAnterior->pNextNode = pNode->pNextNode;
				}
			}

			free(pNode);
			this->size--;
			returnAux = 0;
    	}
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	for(int i=( ll_len(this)-1);i>=0;i--)
    	{
    		returnAux = ll_remove(this, i); //Tambien puede ser ll_remove(this, 0);
    	}
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro y lo retorna
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	for(int i=0;i<ll_len(this);i++)
    	{
    		if(ll_get(this, i) == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this) == 0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	if(returnAux != NULL)
    	{
    		ll_remove(this, index);
    	}
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this, pElement) >= 0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;

	if(this != NULL && this2 != NULL)
	{
		returnAux = 1;

		for(int i=0;i<ll_len(this);i++)
		{
			returnAux = ll_contains(this, ll_get(this2, i));

			if(returnAux == 0)
			{
				break;
			}
		}
	}

	return returnAux;
}

//-----------------------------------------------------------------------------------------------

/** \brief Crea y retorna una nueva lista con los elementos indicados desde 'from' hasta 'to'
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL && from >= 0 && from <= ll_len(this) && to > from && to <= ll_len(this)) //raro
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
			for(int i=from;i<to;i++)
			{
				ll_add(cloneArray, ll_get(this, i));
			}
    	}
    }

    return cloneArray;
}

//-----------------------------------------------------------------------------------------------

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}

//-----------------------------------------------------------------------------------------------

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux = -1;
    void* auxElementoI = NULL;
    void* auxElementoJ = NULL;

	if(this != NULL && (order == 1 || order == 0) && pFunc != NULL)
	{
		for(int i=0;i<(ll_len(this)-1);i++)
		{
			for(int j=i+1;j<ll_len(this);j++)
			{
    			auxElementoI = ll_get(this, i);
    			auxElementoJ = ll_get(this, j);

				if((pFunc(auxElementoI,auxElementoJ) > 0 && order == 1) || (pFunc(auxElementoI,auxElementoJ) < 0 && order == 0))
				{
    				ll_set(this, j, auxElementoI);
    				ll_set(this, i, auxElementoJ);
				}
			}
		}

		returnAux = 0;
	}

	return returnAux;
}

//-----------------------------------------------------------------------------------------------

/**
 * \fn LinkedList ll_filter*(LinkedList*, int(*)(void*))
 * \brief recibe una lista y una función. Itera todos los elementos de la lista y los pasa a la funcion.
 * 		Genera una nueva lista, agrega a la misma los ítems correspondientes y la retorna.
 *
 * \param this LinkedList* Puntero a la lista
 * \param pFunc Puntero a la funcion filtro
 * \return Retorna NULL si se pasa mal algun parametro o la nueva lista
 */
LinkedList* ll_filter (LinkedList* this, int (*pFunc) (void* pElement))
{
    LinkedList* cloneArray = NULL;
    int codigo;

    if(this != NULL && pFunc != NULL)
    {
        LinkedList* listaResultados = NULL;
        void* pAuxElement = NULL;

        if(this != NULL && pFunc != NULL)
        {
        	listaResultados = ll_newLinkedList();
        	if(listaResultados != NULL)
        	{
        		for(int i=0;i<ll_len(this);i++)
        		{
        			pAuxElement = ll_get(this, i);
        			if(pAuxElement != NULL)
        			{
        				if(pFunc(pAuxElement) == 1)
        				{
        					comp_getCodigo(pAuxElement, &codigo);

        					ll_add(listaResultados, pAuxElement);
        				}
        			}
        		}
        	}
        }

        return listaResultados;
    }

    return cloneArray;
}

//-----------------------------------------------------------------------------------------------

/**
 * \fn LinkedList ll_map*(LinkedList*, void*(*)(void*))
 * \brief recibe una lista y una función. Itera todos los elementos de la lista y los pasa a la función, el retorno de “pFunc” se agregará a la lista resultado
 *
 * \param this LinkedList* Puntero a la lista
 * \param pFunc Puntero a la funcion calcular
 * \return Retorna NULL si se pasa mal algun parametro o la nueva lista
 */
LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void* pElement))
{
    LinkedList* listaResultados = NULL;
    void* pAuxElement = NULL;
    void* bufferResultado = NULL;

    if(this != NULL && pFunc != NULL)
    {
    	listaResultados = ll_newLinkedList();
    	if(listaResultados != NULL)
    	{
    		for(int i=0;i<ll_len(this);i++)
    		{
    			pAuxElement = ll_get(this, i);
    			if(pAuxElement != NULL)
    			{
    				bufferResultado = pFunc(pAuxElement);

    				ll_add(listaResultados, bufferResultado);
    			}
    		}
    	}
    }

    return listaResultados;
}

//-----------------------------------------------------------------------------------------------
