# Test-for-Special-Technology-Center

<div id="user-content-toc">
  <ul>
    <summary><h1 style="display: inline-block;">ByteConverter Class</h1></summary>
  </ul>
</div>
Класс `ByteConverter` представляет собой конвертер байтовых данных в строковые значения, основываясь на их типе и данным.

<div id="user-content-toc">
  <ul>
    <summary><h2 style="display: inline-block;">Public методы</h2></summary>
  </ul>
</div>
- `ByteConverter(Source *source, Sink *sink)`: Конструктор класса. Принимает указатели на объекты классов `Source` и `Sink`. Создает экземпляр класса `ByteConverter`.

- `void start()`: Запускает процесс конвертации байтовых данных. Создает новый поток выполнения и вызывает метод `run()`.
- `void stop()`: Останавливает процесс конвертации байтовых данных. Устанавливает флаг `isRunning_` в значение `false` и дожидается завершения потока выполнения.

<div id="user-content-toc">
  <ul>
    <summary><h2 style="display: inline-block;">Private методы</h2></summary>
  </ul>
</div>
- `void run()`: Метод, выполняющий процесс конвертации байтовых данных. В цикле проверяет наличие данных в источнике, читает очередной байт, конвертирует его в строковое значение и записывает в `Sink. В случае ошибки выводит сообщение об ошибке в стандартный поток ошибок.

<div id="user-content-toc">
  <ul>
    <summary><h1 style="display: inline-block;">Sink Class</h1></summary>
  </ul>
</div>
Класс `Sink` представляет интерфейс для записи данных.

<div id="user-content-toc">
  <ul>
    <summary><h2 style="display: inline-block;">Public методы</h2></summary>
  </ul>
</div>
- `virtual void writeData(const std::string &data) = 0`: Виртуальный метод для записи данных. Принимает строку `data`, которую необходимо записать.

<div id="user-content-toc">
  <ul>
    <summary><h1 style="display: inline-block;">Source Class</h1></summary>
  </ul>
</div>
Класс `Source` представляет интерфейс для получения данных.

<div id="user-content-toc">
  <ul>
    <summary><h2 style="display: inline-block;">Public методы</h2></summary>
  </ul>
</div>
- `virtual bool hasDataNext() const = 0`: Виртуальный метод для проверки наличия следующих данных. Возвращает `true`, если есть данные для чтения, и `false` в противном случае.
- `virtual std::uint8_t read() = 0`: Виртуальный метод для чтения очередного байта данных. Возвращает прочитанный байт.
