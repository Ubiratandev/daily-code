# from flask import Flask, request, jsonify
# import speech_recognition as sr
# import io

# app = Flask(__name__)

# @app.route('/convert_audio_to_text', methods=['POST'])
# def convert_audio_to_text():
#     if 'file' not in request.files:
#         return jsonify({"error": "No file part"}), 400

#     file = request.files['file']

#     if file.filename == '':
#         return jsonify({"error": "No selected file"}), 400

#     try:
#         recognizer = sr.Recognizer()

#         # Ler o arquivo de áudio
#         audio_data = file.read()

#         # Converter o áudio em um objeto AudioData para reconhecimento
#         audio_file = sr.AudioData(audio_data, 16000, 2)  # 16000 Hz e 2 bytes por amostra (estéreo)

#         # Reconhecimento de fala com Google Speech Recognition
#         text = recognizer.recognize_google(audio_file)

#         return jsonify({"text": text})

#     except Exception as e:
#         return jsonify({"error": str(e)}), 500

# if __name__ == '__main__':
#     app.run(debug=True)


from flask import Flask, request, jsonify
import speech_recognition as sr
import io

app = Flask(__name__)

@app.route('/convert_audio_to_text', methods=['POST'])
def convert_audio_to_text():
    if 'file' not in request.files:
        return jsonify({"error": "No file part"}), 400

    file = request.files['file']

    if file.filename == '':
        return jsonify({"error": "No selected file"}), 400

    try:
        recognizer = sr.Recognizer()

        # Lê o arquivo de áudio como um objeto em memória
        audio_file = io.BytesIO(file.read())
        print("Arquivo de áudio lido com sucesso.")

        # Processando o áudio
        with sr.AudioFile(audio_file) as source:
            print("Processando áudio...")
            audio_data = recognizer.record(source)

        print("Tentando reconhecer o texto...")
        text = recognizer.recognize_google(audio_data)
        
        print("Texto reconhecido:", text)
        return jsonify({"text": text})

    except Exception as e:
        print("Erro:", str(e))
        return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True)
