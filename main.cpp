#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cstdlib>

using namespace cv;
using namespace std;

int comparaint(const void *a, const void *b){
    return ( *(int*)a - *(int*)b );

}

int main(int argc, char *argv[])
{
    //Número de imagens.
    int tam = 50;
    //Vetor para armazenar os pixels de todas as imagens de uma mesma coordenada.
    int vetor [tam];
    //Vetor para armazenar todas as imagens.
    Mat seqImagem [tam];
    //Caminho da localização das imagens.
    String strArquivos="satelite_ruido/%02i.png";
    //Armazena todas as imagens que satisfazem o caminho no objeto VideoCapture.
    VideoCapture sequencia(strArquivos);
    //Verifica se a sequência de imagens foi aberta.
    if (!sequencia.isOpened())
    {
        cerr << "Falha na abertura da sequência de imagens!\n" << endl;
        return 1;
    }
    //Transfere as imagens carregadas no objeto VideoCapture para o vetor de imagens.
    for (int i=0;i<tam;i++)
    {
        sequencia >> seqImagem[i];
    }
    //Armazena o tamanho de linhas e colunas padrão da imagem.
    int height=seqImagem[0].rows;
    int width=seqImagem[0].cols;
    //Define as resoluções espaciais/contraste das matrizes que receberão o cálculo da média e mediana.
    cv::Mat media(height, width, CV_8U);
    cv::Mat mediana(height, width, CV_8U);
    //Varre os das coordenadas(x,y) de todas as imagens.
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            //Varre todas as imagens.
            for(int img=0; img< tam; img++)
            {
                //Armazena no vetor da mesma posição(x,y) todos os pixels das imagens.
                vetor[img]= seqImagem[img].at<uchar>(i,j);
            }
            //Fazer aqui o cálculo do vetor.
            int soma=0;
            for (int i=0;i<tam;i++){
                soma += vetor[i];
            }
            media.at<uchar>(i,j)=(soma/tam);

            qsort(vetor, 50, sizeof(int), comparaint);
            mediana.at<uchar>(i,j)=(vetor[tam/2]);


        }
    }
    cv::imwrite("satelitemedia.png",media);
    cv::imwrite("satelitemediana.png",mediana);
}

