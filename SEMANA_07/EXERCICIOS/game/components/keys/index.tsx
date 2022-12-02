import React, { useCallback, useEffect } from 'react'
import { Container } from './style'
import { MdOutlineSpaceBar } from 'react-icons/md'
import { AiOutlineEnter } from 'react-icons/ai'
import { toast } from 'react-toastify'

interface Props {
    isRunning: boolean
    playerOneCount: number
    setPlayerOneCount(num: number): void
    playerTwoCount: number
    setPlayerTwoCount(num: number): void
}

const Keys: React.FC<Props> = ({ isRunning, playerOneCount, playerTwoCount, setPlayerOneCount, setPlayerTwoCount }) => {
    const handleKeyPress = useCallback(
        (event: any) => {
            if (isRunning) {
                // Handle space bar press
                if (event.keyCode === 32) {
                    toast.info('Barra de espaço clicada!', {
                        position: toast.POSITION.TOP_LEFT,
                        autoClose: 300,
                    })
                    setPlayerOneCount(playerOneCount + 1)
                }

                // Handle enter press
                if (event.keyCode === 13) {
                    toast.info('Enter clicado!', {
                        position: toast.POSITION.TOP_RIGHT,
                        autoClose: 300,
                    })
                    setPlayerTwoCount(playerTwoCount + 1)
                }
            }
            console.log(event)
        },
        [isRunning, playerOneCount, playerTwoCount, setPlayerOneCount, setPlayerTwoCount]
    )

    useEffect(() => {
        document.addEventListener('keydown', handleKeyPress, false)

        return () => {
            document.removeEventListener('keydown', handleKeyPress, false)
        }
    }, [handleKeyPress])

    return (
        <Container>
            <div>
                <MdOutlineSpaceBar />
                Player one
            </div>
            <div>
                <AiOutlineEnter />
                Player two
            </div>
        </Container>
    )
}

export default Keys
