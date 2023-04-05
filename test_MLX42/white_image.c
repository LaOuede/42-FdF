/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:04:27 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/27 11:14:54 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "MLX42.h"

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)

int32_t	main(void)
{
	// Init mlx with a canvas size of 256x256 and the ability to resize the window.
	mlx_t* mlx = mlx_init(1024, 1024, "MLX42", true);

	if (!mlx) exit(EXIT_FAILURE);

	// Create a 128x128 image.
	mlx_image_t* img = mlx_new_image(mlx, 512, 512);

	// Set the channels of each pixel in our image to the maximum byte value of 255. 
	memset(img->pixels, 255, img->width * img->height * BPP);

	// Draw the image at coordinate (0, 0).
	mlx_image_to_window(mlx, img, 256, 256);

	// Run the main loop and terminate on quit.  
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}
