const { SerialPort } = require("serialport");
const { DelimiterParser } = require("@serialport/parser-delimiter");

const port = new SerialPort({
  path: "COM3",
  baudRate: 9600,
});


const parser = port.pipe(new DelimiterParser({ delimiter: "\n" }));

parser.on("data", (data) => {
  console.log(`Datos recibidos del Arduino: ${data}`);

  // Aquí puedes implementar lógica adicional, por ejemplo:
  // - Envío de datos a una base de datos
  // - Procesamiento con algún modelo de aprendizaje profundo, etc.
});
