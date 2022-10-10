
template<class T>
void LinkedList<T>::swap(T x, T y)
{
	if (x == y)
		return;

	Node<T>* foundX = head;
	Node<T>* prev_foundX = NULL;

	Node<T>* foundY = head;
	Node<T>* prev_foundY = NULL;

	Node<T>* temp = NULL;

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

	if (prev_foundX != NULL)
		prev_foundX->next = foundY;
	else
		head = foundY;

	if (prev_foundY != NULL)
		prev_foundY->next = foundX;
	else
		head = foundX;

	temp = foundX->next;
	foundX->next = foundY->next;
	foundY->next = temp;

	Node<T>* tempT = head;
	while (tempT)
	{
		tail = tempT;
		tempT = tempT->next;
	}
	
}
