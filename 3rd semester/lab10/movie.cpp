// ... Все, прописанное ранее
// Реализация новых методов для дз 10

 // 1. Нисходящее приведение типов (проверяет, какой именно фильм сейчас находится в сеансе, и динамически приводит указатель Movie* к SciFiMovie* или HorrorMovie*, чтобы изменить специфические поля
void MovieSession::ModifyEmbeddedMovieFeatures(const char* newTech, const char* newMonster) {
    if (currentMovie == nullptr) {
        cout << "[Ошибка] Нельзя изменить параметры: фильм не назначен!" << endl;
        return;
    }

    cout << "\n[Downcasting] Попытка изменить специфические параметры фильма \"" << currentMovie->GetTitle() << "\":" << endl;

    // Пытаемся привести к самому нижнему уровню
    HorrorMovie* horrorPtr = dynamic_cast<HorrorMovie*>(currentMovie);
    if (horrorPtr != nullptr) {
        cout << "-> Определен класс HorrorMovie (3 уровень). Меняем технологию и монстра." << endl;
        horrorPtr->SetTechnology(newTech);
        if (newMonster != nullptr) {
            horrorPtr->SetMonsterType(newMonster);
        }
        return;
    }

    // Иначе проверяем на SciFiMovie
    SciFiMovie* scifiPtr = dynamic_cast<SciFiMovie*>(currentMovie);
    if (scifiPtr != nullptr) {
        cout << "-> Определен класс SciFiMovie (2 уровень). Меняем только технологию." << endl;
        scifiPtr->SetTechnology(newTech);
        return;
    }

    // Крайний случай
    cout << "-> Это базовый фильм или неизвестный тип (1 уровень). Специфические параметры отсутствуют." << endl;
}


// 2. СТАТИЧЕСКИЙ МЕТОД (вызывается через имя класса? не привязан к конкретному объекту, сам создает и возвращает новый объект)
MovieSession MovieSession::CreateSessionInteractively(Movie* moviePtr) {
    cout << "\n[Static Method] Запуск создания сеанса через статический метод..." << endl;
    
    char buffer[100];
    int price;

    // Очищаем поток ввода для перестраховки
    cin.clear();
    
    cout << "Введите название зала для нового сеанса: ";
    cin.ignore(cin.rdbuf()->in_avail(), '\n'); // Здесь же очистка буфера
    cin.getline(buffer, 100);

    cout << "Введите цену билета: ";
    cin >> price;

    // Создаем локальный объект с помощью конструктора с параметрами
    MovieSession newCreatedSession(buffer, price, moviePtr);
    
    cout << "[Static Method] Объект сеанса успешно сформирован и возвращается!" << endl;
    return newCreatedSession; 
}
