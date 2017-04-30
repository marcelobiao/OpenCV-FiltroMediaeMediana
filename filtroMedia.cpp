//Número de imagens.
int tam = 50;
//Vetor para armazenar os pixels de todas as imagens de uma mesma coordenada.
int vetor [tam];
//Vetor para armazenar todas as imagens.
Mat seqImagem [tam];
//Caminho da localização das imagens.
string strArquivos="satelite_ruido/%02i.png";
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
	}
}