#include <stdio.h>

int main() {
  // Código para obter a lista de eventos do banco de dados ou de outro local

  printf("Content-type: text/html\n\n");
  printf("<!DOCTYPE html>\n");
  printf("<html>\n");
  printf("<head>\n");
  printf("  <title>Agendamento de Eventos - Lista de Eventos</title>\n");
  printf("</head>\n");
  printf("<body>\n");
  printf("  <h1>Agendamento de Eventos - Lista de Eventos</h1>\n");

  // Loop para exibir os eventos
  printf("  <ul>\n");
  // Código para exibir os eventos obtidos
  printf("    <li><a href=\"editar_evento.cgi?id=1\">Evento 1</a> - <a href=\"remover_evento.cgi?id=1\">Remover</a></li>\n");
  printf("    <li><a href=\"editar_evento.cgi?id=2\">Evento 2</a> - <a href=\"remover_evento.cgi?id=2\">Remover</a></li>\n");
  printf("    <li><a href=\"editar_evento.cgi?id=3\">Evento 3</a> - <a href=\"remover_evento.cgi?id=3\">Remover</a></li>\n");
  printf("  </ul>\n");

  printf("</body>\n");
  printf("</html>\n");

  return 0;
}