# Single thread byte converter

<div id="user-content-toc">
  <ul>
    <summary><h1 style="display: inline-block;">ByteConverter Class</h1></summary>
  </ul>
</div>
The `ByteConverter` class represents a converter for byte data into string values based on their type and data.

<div id="user-content-toc">
  <ul>
    <summary><h2 style="display: inline-block;">Public Methods</h2></summary>
  </ul>
</div>

- `ByteConverter(Source *source, Sink *sink)`: Class constructor. Takes pointers to `Source` and `Sink` objects and creates an instance of the `ByteConverter` class.
- `void start()`: Starts the process of byte data conversion. Creates a new execution thread and calls the `run()` method.
- `void stop()`: Stops the process of byte data conversion. Sets the `isRunning_` flag to `false` and waits for the execution thread to finish.

<div id="user-content-toc">
  <ul>
    <summary><h2 style="display: inline-block;">Private Methods</h2></summary>
  </ul>
</div>

- `void run()`: Method that performs the byte data conversion process. In a loop, it checks for data availability in the source, reads the next byte, converts it into a string value, and writes it to the `Sink`. In case of an error, it outputs an error message to the standard error stream.

<div id="user-content-toc">
  <ul>
    <summary><h1 style="display: inline-block;">Sink Class</h1></summary>
  </ul>
</div>
The `Sink` class represents an interface for writing data.

<div id="user-content-toc">
  <ul>
    <summary><h2 style="display: inline-block;">Public Methods</h2></summary>
  </ul>
</div>

- `virtual void writeData(const std::string &data) = 0`: Virtual method for writing data. Takes a string `data` to be written.

<div id="user-content-toc">
  <ul>
    <summary><h1 style="display: inline-block;">Source Class</h1></summary>
  </ul>
</div>
The `Source` class represents an interface for retrieving data.

<div id="user-content-toc">
  <ul>
    <summary><h2 style="display: inline-block;">Public Methods</h2></summary>
  </ul>
</div>

- `virtual bool hasDataNext() const = 0`: Virtual method for checking if there is more data available. Returns `true` if there is data to read, and `false` otherwise.
- `virtual std::uint8_t read() = 0`: Virtual method for reading the next byte of data. Returns the read byte.
