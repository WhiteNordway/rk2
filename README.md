Степанов В., ИУ1-11Б. ОАиП, РК 2.

//////////////////////////////////////////////////////////////////////
Задание:

Создайте базовый класс Animal для представления животного. У класса
должны быть:

Защищенные данные для хранения имени и вида животного.

Конструктор для инициализации имени и вида.

Виртуальная функция virtual void display() const, которая выводит
информацию о животном.
2 Отнаследуйте от базового класса Animal два класса: Bird и Mammal.

Bird должен иметь размах крыльев и переопределенную функцию
display(), которая выводит информацию о птице.

Mammal должен иметь тип шерсти (короткая, длинная) и
переопределенную функцию display(), которая выводит
информацию о млекопитающем.
3 Создайте STL контейнер (например, std::vector) для хранения
указателей на объекты классов Animal. Заполните контейнер
несколькими объектами Bird и Mammal.
4 Используя итераторы STL, выведите информацию о каждом животном
в контейнере.
5 Напишите функцию, которая принимает указатель на базовый класс
Animal и изменяет его характеристики. Функция должна работать с
любыми производными классами.


////////////////////////////////////////////////////////////////////////////////
Примечание: Все данные заданы на этапе разработки, поток ввода не использовался.