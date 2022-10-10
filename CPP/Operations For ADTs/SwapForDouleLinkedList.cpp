template<class T>
void DList<T>::swap(T x, T y)
{

	if (x == y)
		return;

	DNode<T>* foundX = head;
	DNode<T>* prev_foundX = NULL;

	DNode<T>* foundY = head;
	DNode<T>* prev_foundY = NULL;

	DNode<T>* temp = NULL;

	while (foundX) {
		if (foundX->info == x)
			break;
		else {
			prev_foundX = foundX;
			foundX = foundX->next;
		}
	}

	while (foundY) {
		if (foundY->info == y)
			break;
		else {
			prev_foundY = foundY;
			foundY = foundY->next;
		}
	}


	if (foundX == NULL || foundY == NULL)
		return;

	if (prev_foundX != NULL) {
		prev_foundX->next = foundY;
		}
	else {
		head = foundY;
		head->prev = NULL;
	}

	if (prev_foundY != NULL) {
		prev_foundY->next = foundX;
	}
	else {
		head = foundX;
		head->prev = NULL;	
	}

	DNode<T>* temp1 = NULL;

	foundY->prev = prev_foundX;
	foundX->prev = prev_foundY;

	if (foundX->next)
		foundX->next->prev = foundY;

	
	if (foundY->next)
		foundY->next->prev = foundX;

	temp = foundX->next;
	foundX->next = foundY->next;
	foundY->next = temp;

}
