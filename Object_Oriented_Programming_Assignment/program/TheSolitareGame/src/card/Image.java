package card;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferInt;
import java.awt.image.PixelGrabber;
import java.io.IOException;
import java.io.InputStream;

/**
 * @author Tangrizzly
 * @Create 20/01/2018
 */

public class Image {

    private BufferedImage bufferImage;
    private int width;
    private int height;

    final private int[] pixels;
    final private int[] clear;

    public Image(final String fileName) {
        try {
            System.out.println(fileName);
            InputStream is = this.getClass().getResourceAsStream(fileName);
            BufferedImage tmpImage = ImageIO.read(is);
            width = tmpImage.getWidth(null);
            height = tmpImage.getHeight(null);
            clear = new int[width * height];
            bufferImage = new BufferedImage(width, height,
                    BufferedImage.TYPE_INT_ARGB);
            pixels = ((DataBufferInt) bufferImage.getRaster().getDataBuffer())
                    .getData();
            PixelGrabber pgr = new PixelGrabber(tmpImage, 0, 0, width, height,
                    pixels, 0, width);
            try {
                pgr.grabPixels();
            } catch (InterruptedException ex) {
            }
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    public BufferedImage getBufferedImage() {
        return bufferImage;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

}