from flask import Flask, render_template, request, redirect
import subprocess

app = Flask(__name__)

def ler_eventos():
    eventos = []
    arquivo = open('eventos.txt', 'r')

    for linha in arquivo:
        evento_data = linha.split()
        evento = {
            'nome': evento_data[0],
            'data': evento_data[1],
            'capacidade': int(evento_data[2]),
            'valor': float(evento_data[3])
        }
        eventos.append(evento)

    return eventos

@app.route('/')
def index():
    eventos = ler_eventos()
    return render_template('index.html', eventos=eventos)

@app.route('/adicionar', methods=['POST'])
def adicionar():
    nome = request.form['nome']
    data = request.form['data']
    capacidade = request.form['capacidade']
    valor = request.form['valor']

    subprocess.Popen(['./script', 'adicionar', nome, data, capacidade, valor], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True).communicate()

    return redirect('/')

@app.route('/editar', methods=['POST'])
def editar():
    num_evento = request.form['num_evento']
    eventos = ler_eventos()
    evento = eventos[int(num_evento) - 1]  # Obter o evento selecionado com base no índice
    print(evento)
    return render_template('editar.html', evento=evento)

@app.route('/atualizar', methods=['POST'])
def atualizar():
    num_evento = request.form['num_evento']
    nome = request.form['nome']
    data = request.form['data']
    capacidade = request.form['capacidade']
    valor = request.form['valor']

    print(num_evento, nome, data, capacidade, valor)
    subprocess.Popen(['./script', 'editar', num_evento, nome, data, capacidade, valor], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True).communicate()

    return 'Operação de atualização realizada com sucesso!'

@app.route('/remover', methods=['POST'])
def remover():
    num_evento = request.form['num_evento']

    subprocess.Popen(['./script', 'remover', num_evento], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True).communicate()

    return 'Operação de remoção realizada com sucesso!'

if __name__ == '__main__':
    app.run(port=8000)
