import sys
import os
import tensorflow as tf

def quantize_model(input_file, output_file):
    converter = tf.lite.TFLiteConverter.from_saved_model(input_file)
    converter.optimizations = [tf.lite.Optimize.DEFAULT]
    converter.target_spec.supported_types = [tf.int8]
    converter.inference_input_type = tf.int8
    converter.inference_output_type = tf.int8
    tflite_quant_model = converter.convert()

    with open(output_file, 'wb') as f:
        f.write(tflite_quant_model)

def convert_to_cc(tflite_file, output_file):
    with open(tflite_file, 'rb') as f:
        model_content = f.read()

    with open(output_file, 'w') as f:
        f.write('const unsigned char model[] = {')
        for i in range(len(model_content)):
            f.write(f'0x{model_content[i]:02x}')
            if i < len(model_content) - 1:
                f.write(', ')
            if (i + 1) % 12 == 0:
                f.write('\n')
        f.write('};\n')
        f.write(f'const unsigned int model_len = {len(model_content)};')

if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("Usage: python quantize_and_convert.py <input_saved_model> <output_tflite_model> <output_cc_file>")
        sys.exit(1)

    input_saved_model = sys.argv[1]
    output_tflite_model = sys.argv[2]
    output_cc_file = sys.argv[3]

    quantize_model(input_saved_model, output_tflite_model)
    convert_to_cc(output_tflite_model, output_cc_file)

    print(f"Quantized and converted model saved to: {output_cc_file}")