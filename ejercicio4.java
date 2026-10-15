public class ejercicio4 {

    public static void main(String[] args) {

        // Datos de la compra (Podaci o kupovini)
        // Precio de la unidad (12.5), cantidad comprada (10), si es socio o no (true).
        double precioUnitario = 12.50;
        int cantidad = 10;
        boolean esSocio = true;

        // Constantes del negocio (Konstante poslovanja)
        final double PORCENTAJE_IVA = 0.21;
        final double COSTE_ENVIO_NORMAL = 4.95;
        final double CAMISETAS_POR_CAJA = 4;


        // TODO 1: Calcula el subtotal en una variable double.
        double subtotal = precioUnitario * cantidad;


        // TODO 2: Calcula el porcentaje de descuento en una variable entera "descuento":
        //         Usa if / else if / else. Después, si es socio, súmale 5 al descuento.
        int descuento = 0;
        if (cantidad >= 10) {
            descuento = 15;
        } else if (cantidad >= 5) {
            descuento = 5;
        } else {
            descuento = 0;
        }

        if (esSocio) {
            descuento += 5; // Dodaje se 5% ekstra popusta za članove (socios)
        }


        // TODO 3: Calcula "importeDescontado", aplicando el descuento al subtotal
        double importeDescontado = subtotal - (subtotal * descuento / 100.0);


        // TODO 4: Calcula "costeIva" a partir del importeDescontado y el porcentaje de IVA
        //         y "totalConIva": importeDescontado más el coste del Iva
        double costeIva = importeDescontado * PORCENTAJE_IVA;
        double totalConIva = importeDescontado + costeIva;


        // TODO 5: Decide el coste del envío en una variable double "envio":
        //         0 si totalConIva es más de 50 Ó es socio, y gasto de envío en caso contrario.
        //         Guarda también un String "textoEnvio" que valga "GRATIS" si el envío es 0, o el precio del envío en caso contrario.
        double envio;
        String textoEnvio;

        if (totalConIva > 50 || esSocio) {
            envio = 0.0;
            textoEnvio = "GRATIS";
        } else {
            envio = COSTE_ENVIO_NORMAL;
            textoEnvio = "" + envio;
        }


        // TODO 6: Calcula el total a pagar, que será el precio total con iva más los gastos de envío
        double totalAPagar = totalConIva + envio;


        // TODO 7: Calcula cuántas cajas completas se necesitan para el pedido, y cuántas camisetas sueltas quedan en la última caja.
        int cajasCompletas = cantidad / 4;
        int camisetasSueltas = cantidad % 4;


        // TODO 8: Muestra el ticket completo por pantalla con el formato de la "Salida esperada"
        System.out.println("===== TICKET =====");
        System.out.println("Subtotal: " + subtotal);
        System.out.println("Descuento aplicado: " + descuento + " %");
        System.out.println("Importe descontado: " + importeDescontado);
        System.out.println("IVA (21 %): " + costeIva);
        System.out.println("Envio: " + textoEnvio);
        System.out.println("TOTAL A PAGAR: " + totalAPagar);
        System.out.println("Cajas completas: " + cajasCompletas);
        System.out.println("Camisetas sueltas: " + camisetasSueltas);


        // TODO 9: Si no hay camisetas de sobra en la última caja, muestra "Envio sin cajas incompletas".
        // Si no, muestra "Hay una caja incompleta con X camisetas" siendo X la cantidad de camisetas.
        if (camisetasSueltas == 0) {
            System.out.println("Envio sin cajas incompletas");
        } else {
            System.out.println("Hay una caja incompleta con " + camisetasSueltas + " camisetas");
        }

    }
}