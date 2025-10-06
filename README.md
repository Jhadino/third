# third
3tia laba
Написать игру «Быки и коровы». Компьютер загадывает число из четырех
различных цифр (например, 1356 или 3241). Пользователь пытается угадать это число с
помощью подсказок. Например, если компьютер загадал число 1234, а пользователь ввел
1359, то программа должна ответить: "1 бык и 1 корова". Это значит, что одна цифра (1)
угадана правильно и на правильной позиции, а другая (3) - угадана, но в неправильной
позиции. Угадывание продолжается до вывода: "4 быка" - все цифры угаданы правильно и на
своих позициях.
Написать модуль для подпрограммы угадывания.


1 main
secret = generateSecretNumber();
    attemps = 0;
    guess;
1.1 Создаем цикл (true)
	1.1.1 Введите guess //Считываем число пользователя из строки
	1.1.2 Если guess невалидно - "ERROR" и продолжаем цикл
	1.1.3 Если guess валидно attemps++ 
	1.1.4 result = countBAC(secret, guess); 
	1.1.5 bulls = result.first; cows = result.second;
	1.1.4 Если bulls == 4 выводим secret, attemps и завершаем цикл
	1.1.5 return 0


2 generateSecretNumber(){
    secret = "";
    used [10] = {false};
	2.1 Инициализируем firstDigit от 1 до 9 и передаем true в наш массив used[10] после secret += to_string(firstDigit)
	2.2 Инициализируем digit for (int i = 1; i < 4; i++) и передаем оставшееся цифры в наш массив used[10], после secret += to_string(digit);
	2.3 return secret


3 countBAC(const string& secret, const string& guess)
    int bulls = 0;
    int cows = 0;
	3.1 for (int i = 0; i < 4; i++)
		3.1.1 Если (guess[i] == secret[i]) bulls++ // Если число на том же месте где у загаданного числа
		3.1.2 Иначе for (int j = 0; j < 4; j++)
			3.1.2.1 Если (i != j && guess[i] == secret[j]) cows++; // Если число не на том же месте
 	3.2 break
	3.3 return make_pair(bulls, cows)
4 isValid(const string& guess)
	4.1 если guess.length() !=4 return false // Проверка длинны
	4.2 set<char> uniqueChars; // Убираем повторяющиеся числа
	4.3 for (char c : guess) // Для каждого символа
		4.3.1 Если (!isdigit(c)) return false // Проверка является ли цифрой
		4.3.2 uniqueChars.insert(c); // Добавление символа в набор
	4.4 return uniqueChars.size() == 4; // Возвращение  числа из 4 уникальных цифр