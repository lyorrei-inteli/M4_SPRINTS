import styled from 'styled-components'

export const Container = styled.div`
    display: grid;
    width: 100%;
    grid-template-columns: 1fr 1fr;
    justify-items: center;
    padding: 8rem 0;

    div {
        font-size: 4rem;
        color: ${(props) => props.theme.colors.white};
        display: flex;
        flex-direction: column;
        align-items: center;

        svg {
            fill: ${(props) => props.theme.colors.white};
            font-size: 16rem;
        }
    }
`
